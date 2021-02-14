lmake_compatibility_version(1)

--src_files = lmake_find("src/*c");
src_files = "src/main.c src/func.c";
--link_files = lmake_find("build/*.o");
link_files = "build/main.c.o build/func.c.o";

function build()
	lmake_set_compiler("/bin/gcc")
	lmake_set_compiler_flags("-Wall -Iinclude -lm")
	lmake_set_compiler_out("build/%.o")
	lmake_compile(src_files)
	lmake_set_linker_flags("-lm")
	lmake_set_linker("/bin/gcc")
	lmake_set_linker_out("bid_alg")
	lmake_link(link_files)
end

function clean()
	lmake_exec("rm -rf"..link_files)
	lmake_exec("rm -rf bid_alg")
end

function run()
	lmake_exec("./bid_alg")
end
