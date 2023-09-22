#define NOBUILD_IMPLEMENTATION
#include "./nobuild.h"

#define BIN "build/smw"
#define DEBUGGER "gf2"
#define DESTDIR "/usr/local/bin"
#define CACHE "assets/__pycache__"
#define CC "clang"

//				"-Wextra", \
//				"-Werror", \
//				"-Wfatal-errors", \
//				"-pedantic", \
//				"-pedantic-errors", \
//				"-Wall", \
//				"-O0",
//				"-std=c2x", \

#define CFLAGS  "-fno-strict-aliasing", \
				"-Wno-unused-variable", \
				"-I/usr/include/SDL2", \
                "-DSYSTEM_VOLUME_MIXER_AVAILABLE=0", \
                "-I."

#define SRCS "smb1/smb1_00.c", \
             "smb1/smb1_01.c", \
             "smb1/smb1_02.c", \
             "smb1/smb1_08.c", \
             "smb1/smb1_cpu_infra.c", \
             "smb1/smb1_spc_player.c", \
             "smbll/smbll_00.c", \
             "smbll/smbll_01.c", \
             "smbll/smbll_02.c", \
             "smbll/smbll_08.c", \
             "smbll/smbll_0b.c", \
             "smbll/smbll_cpu_infra.c", \
             "src/common_cpu_infra.c", \
             "src/common_rtl.c", \
             "src/config.c", \
             "src/glsl_shader.c", \
             "src/lm.c", \
             "src/main.c", \
             "src/opengl.c", \
             "src/smw_00.c", \
             "src/smw_01.c", \
             "src/smw_02.c", \
             "src/smw_03.c", \
             "src/smw_04.c", \
             "src/smw_05.c", \
             "src/smw_07.c", \
             "src/smw_0c.c", \
             "src/smw_0d.c", \
             "src/smw_cpu_infra.c", \
             "src/smw_rtl.c", \
             "src/smw_spc_player.c", \
             "src/tracing.c", \
             "src/util.c", \
             "src/snes/apu.c", \
             "src/snes/cart.c", \
             "src/snes/cpu.c", \
             "src/snes/dma.c", \
             "src/snes/dsp.c", \
             "src/snes/ppu.c", \
             "src/snes/ppu_old.c", \
             "src/snes/snes.c", \
             "src/snes/snes_other.c", \
             "src/snes/spc.c", \
             "third_party/gl_core/gl_core_3_1.c"

/* TODO:
 *		 buld objs separately
 *		 move build to build folder
 *		 enable warning solve then
 *		 enable extra warnings
 */

int posix_main(int argc, char **argv){
    if (argc == 1){
    	CMD(CC, "-o", BIN, SRCS, CFLAGS, "-lm", "-lSDL2", NULL);
    	CMD("python3", "assets/restool.py", NULL);
	}

    if (argc > 1){
        if (strcmp(argv[1], "run") == 0){
            CMD("./"BIN);
        }else if (strcmp(argv[1], "gdb") == 0){
            CMD(DEBUGGER, BIN);
        }else if (strcmp(argv[1], "install") == 0){
			CMD("doas", "cp", BIN, DESTDIR);
        }else if (strcmp(argv[1], "remove") == 0){
			CMD("doas", "rm", "-v", DESTDIR"/"BIN);
        }else if (strcmp(argv[1], "clean-bin") == 0){
			CMD("rm -v", BIN);
        }else if (strcmp(argv[1], "clean-pycache") == 0){
			CMD("rm -rv", CACHE );
        }else if (strcmp(argv[1], "clean-all") == 0){
			CMD("rm -rv", BIN, CACHE);
        }else{
            PANIC("%s is unknown subcommand", argv[1]);
        }
    }
    return EXIT_SUCCESS;
}

int main(int argc, char *argv[]) {
    GO_REBUILD_URSELF(argc, argv);

    return posix_main(argc, argv);
}
