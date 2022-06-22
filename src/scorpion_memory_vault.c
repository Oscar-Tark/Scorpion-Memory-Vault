#include "./headers/network/server.h"
#include "./headers/memory/types.h"
#include "./headers/basic/variadic.h"
#include "./headers/memory/memory_struct.h"
#include "./headers/memory/memory.h"

void test();

int main(int argc, char* argv[]){
	char* out[argc];
	getArgvVariadic(2, argv, argc, out, "-ip", "-p");

	test();

	server("127.0.0.1", 8777);
	return 0;
}

void test(){
	//Testing pstring functionality
	pString id = newpString();
	id = setpString(id, "Henlo");

	printf("%s\n", id);

	freepString(id);

	//Testing allocation, find, delete
//	int success = alloc(id, id, id);
}
