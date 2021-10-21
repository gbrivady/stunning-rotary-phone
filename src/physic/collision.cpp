#include "physic/collision.hpp"

void checkCollisions(vector<Entity>* entities, Terrain terrain){
    tuple<double, tuple<double, double>> tempCol;
    double temp;
    for (int i = 0; i < (*entities).size(); i++)
    {
        for(int j = i+1; j < (*entities).size(); j++){
            tempCol = collideHTBX((*entities)[i].getHitbox(), (*entities)[i].getPosition(),
                           (*entities)[j].getHitbox(), (*entities)[j].getPosition());
            if(get<0>(tempCol)>0){
                (*entities)[i].onCollision((*entities)[j], tempCol);
            }
        }
        //Check collision with terrain
        tempCol = collideTRRN((*entities)[i], terrain);
        if(get<0>(tempCol)>0){
            (*entities)[i].onCollision(terrain, tempCol);
        }
    }
    
}

tuple<double, tuple<double, double>> collideTRRN(Entity entity, Terrain terrain){
    tuple<double, double> entPos = entity.getPosition();
    double xEnt = get<0>(entPos);
    double yEnt = get<1>(entPos);
    tuple<double, tuple<double, double>> terCol = terrain.hitbox(xEnt, yEnt);
    return terCol;
}

tuple<double, tuple<double, double>> collideHTBX(Hitbox hitbox1, tuple<double, double> g1, 
                                             Hitbox hitbox2, tuple<double, double> g2){
    vector<tuple<double, double>> vertices1 = hitbox1.getVertices();
    vector<tuple<double, double>> vertices2 = hitbox2.getVertices();
    int nbV1 = vertices1.size();
    int nbV2 = vertices2.size();
    tuple<double, double> vertex1;
    tuple<double, double> vertex2;
    tuple<double, double> normalVct;
    tuple<double, tuple<double, double>> returnValue;
    double pushDist = -3;

    for(int i = 0; i < nbV1; i++){
        vertex1 = vertices1[i];
        vertex2 = vertices2[(i+1)%nbV1];
        normalVct = normalVector(vertex1, vertex2);
        //check if the normal vector is a separating axis
        pushDist = isSeparatingAxis(normalVct, vertices1, g1, vertices2, g2);
        if(pushDist < 0){
            //then they do not collide
            return make_tuple(-1, make_tuple(0, 0));
        }
        //else we only keep the smallest dist and its normal vector
        if(pushDist < get<0>(returnValue)){
            get<0>(returnValue) = pushDist;
            get<1>(returnValue) = normalVct;
        }
    }
    return returnValue;
}

double isSeparatingAxis(tuple<double, double> n, 
                        vector<tuple<double, double>> vertices1,
                        tuple<double, double> g1,
                        vector<tuple<double, double>> vertices2,
                        tuple<double, double> g2){
    double dist = -1;
    double proj;
    double min1 = -numeric_limits<double>::max();
    double min2 = -numeric_limits<double>::max();
    double max1 = numeric_limits<double>::max();
    double max2 = numeric_limits<double>::max();
    for (int i = 0; i < vertices1.size(); i++)
    {
        proj = inner_product(n, vertices1[i], g1);
        min1 = min(proj, min1);
        max1 = max(proj, max1);
    }
    for (int i = 0; i < vertices2.size(); i++)
    {
        proj = inner_product(n, vertices2[i], g2);
        min2 = min(proj, min2);
        max2 = max(proj, max2);
    }
    if(max1 >= min2 && max2 >= min1){
        return min(max2 - min1, max1 - min2); //return distance on n axis if it is *not* a separating axis
    }
    return -1; //negative value if it is a separating axis
    
}

double inner_product(tuple<double, double> t1, tuple<double, double> t2){
    return get<0>(t1)*get<0>(t2) + get<1>(t1)*get<0>(t2);
}

double inner_product(tuple<double, double> t1, tuple<double, double> t2, tuple<double, double> g2){
    return get<0>(t1)*(get<0>(t2)+get<0>(g2)) + get<1>(t1)*(get<1>(t2)+get<1>(g2));
}

tuple<double, double> normalize(tuple<double, double> t){
    double n = sqrt(inner_product(t, t));
    return make_tuple(get<0>(t)/n, get<1>(t)/n);
}

tuple<double, double> normalVector(tuple<double, double> t1, tuple<double, double> t2){
    tuple<double, double> n = make_tuple(get<1>(t2) - get<1>(t1), get<0>(t1) - get<0>(t2));
    return normalize(n);
}
