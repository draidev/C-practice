#include "hash_table.h"

int main(void){
	FILE *hash_csv = NULL;
	hash_table_t *hash_tbl = NULL;
	char str_tmp[STRLEN];

	hash_tbl = hash_table_alloc(hash_tbl);
	hash_csv = fopen("hash.csv", "r");
	if(hash_csv){
		while(fgets(str_tmp, STRLEN, hash_csv) != NULL){
			append_list(hash_tbl, str_tmp);
		}
	}
	else
		fprintf(stderr, "fileopen error!!");

	show_hash_table(hash_tbl);

	fclose(hash_csv);
	linked_list_free(hash_tbl);
	hash_table_free(hash_tbl);

return 0;
}
