#include "hash_table.h"

int main(void){
	FILE *hash_csv = NULL;
	hash_table_t *hash_tbl = NULL;
	char str_tmp[STRLEN];

	hash_table_alloc(hash_tbl);
	hash_csv = fopen("hash.csv", "r");
	if(hash_csv){
		while(fgets(str_tmp, STRLEN, hash_csv) != NULL){
			printf("str_tmp : %s", str_tmp);
			append_list(hash_tbl, str_tmp);
		}
	}
	else
		fprintf(stderr, "fileopen error!!");

	fclose(hash_csv);
	hash_table_free(hash_tbl);

return 0;
}
