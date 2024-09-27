
#include "vlinteger.h"
#include <stdlib.h>
#include <stdio.h>

struct linteger *vlintegerCreate(void)
{
	struct linteger *t1 = malloc(sizeof(struct linteger));
	t1->arr = NULL;
	t1->length = 0;	// no values in t1.
	return t1;
}

void vlintegerPrint(struct linteger *t1)
{
	printf("length=%d\n", t1->length);
	for (int i = 0; i < t1->length; i++)
	{
		printf("%d", t1->arr[i]);
	}
	printf("\n");
}

void vlintegerDestroy(struct linteger *t1)
{
	if (t1)
	{
		free(t1->arr);	// free the inside array first
		free(t1);	// then free the structure
	}
}

void vlintegerRead(struct linteger *t1)
{
	int curr = 0;
	int counter = 0;

	while(scanf("%d", &curr)){
		t1->arr = realloc(t1->arr, (counter+1)*sizeof(int));
		if(t1->arr == NULL){
			exit(1);
		}
		t1->arr[counter] = curr;

		++counter;
	}

	t1->length = counter;

}

struct linteger *vlintegerAdd(struct linteger *t1, struct linteger *t2)
{
    int max_len = (t1->length > t2->length) ? t1->length : t2->length;
    struct linteger *sum = vlintegerCreate();
    sum->arr = malloc((max_len) * sizeof(int));

    int carry = 0;
    int i = t1->length - 1;
    int j = t2->length - 1;
    int k = max_len-1;

    while (i >= 0 || j >= 0 ) {
        int num1 = (i >= 0) ? t1->arr[i] : 0;
        int num2 = (j >= 0) ? t2->arr[j] : 0;
        int total = num1 + num2 + carry;

        carry = total / 10;
        sum->arr[k] = total % 10;


        --i;
        --j;
        --k;
    }

    sum->length = max_len;

    // If there's a carry after all additions, increase the length and insert the carry.
    if (carry) {
		struct linteger *clone = vlintegerCreate();
		clone->arr = malloc((max_len+1)*sizeof(int));
		clone->length = max_len+1;

		for(int i=1 ; i<=max_len ; i++){
			clone->arr[i] = sum->arr[i-1];
		}
		clone->arr[0] = carry;

		vlintegerDestroy(sum);
		return clone;

    }else{
		return sum;
	}

}

struct linteger *vlintegerMult(struct linteger *t1, struct linteger *t2)
{
	int max_len = t1->length + t2->length;
	struct linteger *product = vlintegerCreate();
	product->arr = malloc((max_len)*sizeof(int));
	
	for(int i=0 ; i<max_len ; i++){
		product->arr[i]=0;
	}

	int sum = 0;
	int carry = 0;
	int k = max_len-1;

	if(t1->length >= t2->length){
		for(int i=t2->length-1 ; i>=0 ; i--){
			for(int j=t1->length-1 ; j>=0 ; j--){
				sum = t1->arr[j]*t2->arr[i];

				carry = sum/10;
				product->arr[k] += sum%10;
				product->arr[k-1] += carry;

				if(product->arr[k] > 9){
					product->arr[k-1] += product->arr[k]/10;
					product->arr[k]%=10;
				}
				--k;
			}
			k += t1->length - 1;
		}
	}else{
		for(int i=t1->length-1 ; i>=0 ; i--){
			for(int j=t2->length-1 ; j>=0 ; j--){
				sum = t2->arr[j]*t1->arr[i];

				carry = sum/10;
				product->arr[k] += sum%10;
				product->arr[k-1] += carry;

				if(product->arr[k] > 9){
					product->arr[k-1] += product->arr[k]/10;
					product->arr[k]%=10;
				}
				--k;
			}
			k += t2->length - 1;
		}
	}//end else

	product->length = max_len;

	if(product->arr[0] != 0){
		product->length = max_len;
		return product;
	}
	else{
		struct linteger *clone = vlintegerCreate();
		clone->arr = malloc((max_len-1)*sizeof(int));

		for(int i=0 ; i<max_len-1 ; i++){
			clone->arr[i] = product->arr[i+1];
		}
			
		vlintegerDestroy(product);
		clone->length = max_len-1;
		return clone;		
	}
}
