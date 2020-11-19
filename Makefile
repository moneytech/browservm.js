BUILD_TYPE=EMSCRIPTEN
DEBUGFLAGS = -O2 -g
CC=clang
CXX=clang++
DEFINEFLAGS =  -DNEED_CPU_H \
	-DTARGET_INSN_START_EXTRA_WORDS=1 -DCONFIG_SOFTMMU  \
	-D__STDC_FORMAT_MACROS
INCLUDEFLAGS = -I libq/include/ -I libtcg/include/ \
-I glib/ -I glib/glib \
-I libcpu/include -I libcpu/include/cpu -I libcpu/include/fpu \
-I libcpu/target-i386/ -I libcpu/ 
CFLAGS = -Wno-initializer-overrides $(DEFINEFLAGS) $(DEBUGFLAGS)

LDFLAGS = -lm 
C_LINK = $(CC) -o $@ $(LDFLAGS) $(DEBUGFLAGS) 
CXX_LINK = $(CXX) -o $@ $(LDFLAGS) $(DEBUGFLAGS) 

glibsources = glib/gmsg.c \
		 glib/ghash.c \
		 glib/gmem.c \
		 glib/gstrfuncs.c \
		 glib/gslist.c \
		 glib/glist.c \
		 glib/gstring.c \
		 glib/gbytes.c \
		 glib/gmain.c \
		 glib/gqueue.c \
		 glib/gtree.c \
		 glib/garray.c \
		 glib/gqsort.c 

libqsources = libq/json-lexer.c \
     libq/qbool.c \
     libq/qint.c \
     libq/qstring.c \
	 libq/json-parser.c \
	 libq/qdict.c \
	 libq/qjson.c \
	 libq/json-streamer.c \
	 libq/qfloat.c \
	 libq/qlist.c 

libtcgsources = libtcg/cutils.c \
	libtcg/tcg.c \
	libtcg/tcg-common.c \
	libtcg/tcg-op.c \
	libtcg/optimize.c \
	libtcg/tcg-op-gvec.c \
	libtcg/tcg-runtime-gvec.c \
	libtcg/tcg-runtime.c \
	libtcg/tcg-op-vec.c 

libcpusources = \
	libcpu/exec-tlb.c \
	libcpu/ioport.c \
	libcpu/memory.c \
	libcpu/timer.c \
	libcpu/translate-all.c \
    libcpu/fpu/softfloat.c \
    libcpu/precise-pc.c \
    libcpu/disas.c \
    libcpu/exec-bp.c \
	libcpu/exec-log.c \
	libcpu/exec-memdbg.c \
	libcpu/exec-phys.c \
	libcpu/exec-phystb.c \
	libcpu/exec-ram.c \
    libcpu/target-i386/cpuid.c \
    libcpu/target-i386/helper.c \
    libcpu/target-i386/op_helper.c \
    libcpu/target-i386/translate.c \
    libcpu/cpus.c \
    libcpu/exec.c \
    libcpu/exec-tb.c \
	libcpu/cpu-exec.c 

vmsources = main.c \
    peripheral.c \
    virtio.c \
    

ifeq ($(BUILD_TYPE),I386)
		DEFINEFLAGS += -DI386_BUILD -DTARGET_X86_64 -DTARGET_LONG_BITS=64
endif

ifeq ($(BUILD_TYPE),INTERPRET)
	 libtcgsources += libtcg/tci/tci.c
	 DEFINEFLAGS += -DCONFIG_TCG_INTERPRETER -DINTERPRET_BUILD -DTARGET_X86_64 -DTARGET_LONG_BITS=64
endif

ifeq ($(BUILD_TYPE),EMSCRIPTEN)
	 libtcgsources += libtcg/tci/tci.c
	 DEFINEFLAGS += -DCONFIG_TCG_INTERPRETER -DINTERPRET_BUILD -DTARGET_LONG_BITS=32 
	 CC=emcc
	 CXX=em++
	 C_LINK += -s NO_EXIT_RUNTIME=1 -s WASM=1 -s ALLOW_MEMORY_GROWTH=1 --pre-js preload.js \
	 -s EXPORTED_FUNCTIONS='["_main", "_main_exec_loop"]' --js-library library.js
	 DEBUGFLAGS = -O3 -g -fno-rtti -fno-exceptions
endif

glibobjects = $(glibsources:.c=.o)

libqobjects = $(libqsources:.c=.o)

libtcgobjects = $(libtcgsources:.c=.o)

libcpuobjects = $(libcpusources:.c=.o)

vmobjects = $(vmsources:.c=.o)


emulator.js: $(glibobjects) $(libqobjects) $(libtcgobjects) $(libcpuobjects) $(vmobjects)
	$(C_LINK) $(glibobjects) $(libqobjects) $(libtcgobjects) $(libcpuobjects) $(vmobjects)

$(glibobjects): %.o: %.c
	$(CC)  -c $(CFLAGS) $(INCLUDEFLAGS) $< -o $@

$(libqobjects): %.o: %.c
	$(CC)  -c $(CFLAGS) $(INCLUDEFLAGS) $< -o $@

$(libtcgobjects): %.o: %.c
	$(CC)  -c $(CFLAGS) $(INCLUDEFLAGS) $< -o $@

$(libcpuobjects): %.o: %.c
	$(CC)  -c $(CFLAGS) $(INCLUDEFLAGS)  $< -o $@

$(vmobjects): %.o: %.c
	$(CC)  -c $(CFLAGS) $(INCLUDEFLAGS)  $< -o $@

clean:
	rm -f emulator* \
	*.o \
	libq/*.o \
	glib/*.o \
	libtcg/*.o \
	libtcg/i386/*.o \
	libtcg/tci/*.o \
	libtcg/jit/*.o \
	libcpu/*.o \
	libcpu/fpu/*.o \
	libcpu/target-i386/*.o 

	
	
