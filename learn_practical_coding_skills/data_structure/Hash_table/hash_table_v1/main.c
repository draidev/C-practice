#include "hash_table.h"

int main(void){
	FILE *hash_csv = NULL;
	linked_list_t *lnk_lst = NULL;
	hash_table_t *hash_tbl = NULL;

	hash_csv = fopen("hash.csv", "r");
	hash_table_alloc(hash_tbl);

	linked_list_alloc(lnk_lst);
	get_hashkey_n_data(hash_csv, hash_tbl, lnk_lst);

	//printf("hash_: %s\n", (hash_linked_list+0)->hash_key);
	//get_hashkey_n_data(hash_csv, hash_linked_list);

	fclose(hash_csv);
	linked_list_free(lnk_lst);
	hash_table_free(hash_tbl);

return 0;
}
