/*

set bucket = all nodes in graph


min_dist = array


set all elements in min_dist to infinity


set min_dist[source] = 0

while bucket is not empty


loop


    current_node = get the node from bucket with least dist


    remove current_node from bucket



    for each neighbor of current_node



    loop


        new_dist = distance from source to current_node + distance from current_node to neighbor


        old_dist = min_dist[neighbor]




        if new_dist < old_dist


            min_dist[neighbor] = new_dist



    end loop
end loop

*/



#include <iostream>


#include <graphlib.h>

using namespace std;


using namespace graphlib;



graph g;


edge_weight w(g);



const int number_of_nodes = 4;


const int number_of_edges = 5;


const int infinity = 10000;



int source_node = 3;



int bucket[number_of_nodes];



int min_dist[number_of_nodes];



void create_graph()



{


    generate_random_weighted_graph(g, w, number_of_nodes, number_of_edges);


    print_graph(g, w);


}




void initialize()



{



    for(int i=0; i<number_of_nodes; i++)


    {



        bucket[i] = i;



        min_dist[i] = infinity;



    }



    min_dist[source_node] = 0;



}





bool not_empty(int bucket[])



{



    for(int i=0; i<number_of_nodes; i++)



        if( bucket[i] != -1 )



            return true;



    return false;



}




int node_from_bucket_with_least_dist()



{


    int min = infinity;



    int node_with_min;



    for(int i=0; i<number_of_nodes; i++)



    {


        if( bucket[i] == -1)



            continue;





        int dist = min_dist[i];



        if( dist < min)



        {



            min = dist;



            node_with_min = i;


        }



    }



    return node_with_min;



}





void dijkstra()



{



    initialize();





    while( not_empty(bucket))



    {



        int current_node;



        current_node = node_from_bucket_with_least_dist();


        bucket[current_node] = -1;





        int neighbor;



        forall_adjacent_node_ids(neighbor, current_node, g)



        {


            int distance_from_source_to_current_node = min_dist[current_node];



            int distance_from_current_node_to_neighbor = weight_of_edge(current_node, neighbor, g, w);




            int new_dist = distance_from_source_to_current_node + distance_from_current_node_to_neighbor;



            int old_dist = min_dist[neighbor];




            if( new_dist < old_dist)


                min_dist[neighbor] = new_dist;



        }



    }



}




void print()



{


    for(int i=0; i<number_of_nodes; i++)



        cout << "\n Min distance from " << source_node << " to " << i << " is " << min_dist[i];



}




int main()



{


    create_graph();



    dijkstra();

    print();



    return 0;



}


