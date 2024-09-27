#include <stdio.h>
#include <assert.h>

typedef struct Point{
	int x;
	int y;
} point;

typedef struct Rectangle {
   point bottomLeft;
   int width;
   int height;
} rectangle;


rectangle intersection(rectangle rects[], int n){
	rectangle intersection = rects[0];

	for(int i=1; i<n ; i++){
		rectangle curr = rects[i];

		if(intersection.bottomLeft.x + intersection.width <= curr.bottomLeft.x || curr.bottomLeft.x + curr.width <= intersection.bottomLeft.x){
			rectangle noIntersec = {{0,0},0,0};
			return noIntersec;
		}
		if(intersection.bottomLeft.y + intersection.height <= curr.bottomLeft.y || curr.bottomLeft.y + curr.height <= intersection.bottomLeft.y){
			rectangle noIntersec = {{0,0},0,0};
			return noIntersec;
		}		

		//calc bottom left of intersetion
		intersection.bottomLeft.x = (curr.bottomLeft.x > intersection.bottomLeft.x) ? curr.bottomLeft.x : intersection.bottomLeft.x;
		intersection.bottomLeft.y = (curr.bottomLeft.y > intersection.bottomLeft.y) ? curr.bottomLeft.y : intersection.bottomLeft.y;
		// printf("%d", intersection.bottomLeft.x);
		// printf("%d ", intersection.bottomLeft.y);

		//calcs the width and height for intersection and current to compare them
		int x1 = intersection.bottomLeft.x + intersection.width;
		int y1 = intersection.bottomLeft.y + intersection.height;

		int x2 = curr.bottomLeft.x + curr.width;
		int y2 = curr.bottomLeft.y + curr.height;
		// printf("%d,%d ", x1,y1);
		// printf("%d,%d ", x2,y2);

		intersection.width = (x1 < x2 ? x1 : x2 ) - intersection.bottomLeft.x;
		intersection.height = (y1 < y2 ? y1 : y2 ) - intersection.bottomLeft.y;
		// printf("%d", intersection.width);
		// printf("%d\n", intersection.height);

	}

	return intersection;

}

// int main(){
	
// 	rectangle result;

// 	rectangle r = {{2,6},3,4};
// 	rectangle s = {{0,7},7,1};
// 	rectangle t = {{3,5},1,6};
// 	rectangle u = {{5,6},3,4};
	
// 	// Test 1
// 	rectangle rects1[2] = {r, s};
// 	result = intersection(rects1, 2);	
// 	assert(result.bottomLeft.x == 2);
// 	assert(result.bottomLeft.y == 7);
// 	assert(result.width == 3);
// 	assert(result.height == 1);
	

// 	// Test 2
// 	rectangle rects2[3] = {r, s, t};
// 	result = intersection(rects2, 3);
// 	assert(result.bottomLeft.x == 3);
// 	assert(result.bottomLeft.y == 7);
// 	assert(result.width == 1);
// 	assert(result.height == 1);
	
	
// 	// Test 3
// 	rectangle rects3[4] = {r, s, t, u};
// 	result = intersection(rects3, 4);
// 	assert(result.bottomLeft.x == 0);
// 	assert(result.bottomLeft.y == 0);
// 	assert(result.width == 0);
// 	assert(result.height == 0);


// 	return 0;
// }
