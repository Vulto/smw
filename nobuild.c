#define NOBUILD_IMPLEMENTATION
#include "./nobuild.h"

#define BIN "build/smw"
#define DEBUGGER "gf2"
#define DESTDIR "/usr/local/bin"
#define CACHE "assets/__pycache__"
#define CC "gcc"

#define CFLAGS	"-I/usr/include/SDL2",					\
                "-DSYSTEM_VOLUME_MIXER_AVAILABLE=0",	\
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

#if 0
enable warning solve then
enable extra warnings

void BuildObj(void) {
    CMD(CC, "-o", OBJ, "-c", SRCS);
}
#endif

void BuildBin(void) {
    CMD(CC, "-o", BIN, SRCS, CFLAGS, "-lm", "-lSDL2", NULL);
    CMD("python3", "assets/restool.py", NULL);
}

void Install(void) {
	CMD("doas", "cp", BIN, DESTDIR);
}

void Remove(void) {
	CMD("doas", "rm", "-v", DESTDIR""BIN);
}

#if 0
void Clean(void) {
	size_t objarr = (sizeof(OBJECTS) / sizeof(OBJECTS[1]));
	for (int i=0; i < objarr ; i++) {
		CMD("rm", OBJECTS[i]);
	}
	CMD("rm", BIN, "c.old");
}
#endif 

int Usage(void) {
	printf("Usage");
	return EXIT_FAILURE;
}

int main(int argc, char *argv[]) {
	
    GO_REBUILD_URSELF(argc, argv);
    if (argc < 2 ){
		BuildBin();
		return EXIT_SUCCESS;
	}

    if (argc < 2) {
        return 1;
    }

	for (int i = 1; i < argc; i++) {
		char *arg = argv[i];

		if (arg[0] == '-') {
			for (int j = 1; j < strlen(arg); j++) {

				switch (arg[j]) {
					case 'r':
						Remove();
						break;
					case 'i':
						Install();
						break;
					case 'c':
//						Clean();
						break;
					default:
						printf("Unknown option: %c\n", arg[j]);
						break;
				}
			}
		} else {
			printf("Usage: %s [-d] [-r] [-f]\n", argv[0]);
		}
    }

    return EXIT_SUCCESS;
}
