cmake_minimum_required(VERSION 3.15)
project(CieOS C ASM)

set(CMAKE_C_STANDARD 11)

set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} -nostdlib")

set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -masm=intel -Wno-builtin-declaration-mismatch -mgeneral-regs-only -g3")
set(CMAKE_ASM_FLAGS "${CMAKE_ASM_FLAGS} -masm=intel")

include_directories(include)
add_library(CieOS SHARED
        src/std.c
        src/font/hankaku.c
        src/descriptor/segment.c
        src/descriptor/interrupt.c
        src/graphics/draw.c
        src/graphics/print.c
        src/memory_allocator/print.c
        src/main.c

        handler/int_0.c handler/int_1.c handler/int_2.c handler/int_3.c handler/int_4.c handler/int_5.c handler/int_6.c handler/int_7.c handler/int_8.c handler/int_9.c handler/int_10.c handler/int_11.c handler/int_12.c handler/int_13.c handler/int_14.c handler/int_15.c handler/int_16.c handler/int_17.c handler/int_18.c handler/int_19.c handler/int_20.c handler/int_21.c handler/int_22.c handler/int_23.c handler/int_24.c handler/int_25.c handler/int_26.c handler/int_27.c handler/int_28.c handler/int_29.c handler/int_30.c handler/int_31.c handler/int_32.c handler/int_33.c handler/int_34.c handler/int_35.c handler/int_36.c handler/int_37.c handler/int_38.c handler/int_39.c handler/int_40.c handler/int_41.c handler/int_42.c handler/int_43.c handler/int_44.c handler/int_45.c handler/int_46.c handler/int_47.c handler/int_48.c handler/int_49.c handler/int_50.c handler/int_51.c handler/int_52.c handler/int_53.c handler/int_54.c handler/int_55.c handler/int_56.c handler/int_57.c handler/int_58.c handler/int_59.c handler/int_60.c handler/int_61.c handler/int_62.c handler/int_63.c handler/int_64.c handler/int_65.c handler/int_66.c handler/int_67.c handler/int_68.c handler/int_69.c handler/int_70.c handler/int_71.c handler/int_72.c handler/int_73.c handler/int_74.c handler/int_75.c handler/int_76.c handler/int_77.c handler/int_78.c handler/int_79.c handler/int_80.c handler/int_81.c handler/int_82.c handler/int_83.c handler/int_84.c handler/int_85.c handler/int_86.c handler/int_87.c handler/int_88.c handler/int_89.c handler/int_90.c handler/int_91.c handler/int_92.c handler/int_93.c handler/int_94.c handler/int_95.c handler/int_96.c handler/int_97.c handler/int_98.c handler/int_99.c handler/int_100.c handler/int_101.c handler/int_102.c handler/int_103.c handler/int_104.c handler/int_105.c handler/int_106.c handler/int_107.c handler/int_108.c handler/int_109.c handler/int_110.c handler/int_111.c handler/int_112.c handler/int_113.c handler/int_114.c handler/int_115.c handler/int_116.c handler/int_117.c handler/int_118.c handler/int_119.c handler/int_120.c handler/int_121.c handler/int_122.c handler/int_123.c handler/int_124.c handler/int_125.c handler/int_126.c handler/int_127.c handler/int_128.c handler/int_129.c handler/int_130.c handler/int_131.c handler/int_132.c handler/int_133.c handler/int_134.c handler/int_135.c handler/int_136.c handler/int_137.c handler/int_138.c handler/int_139.c handler/int_140.c handler/int_141.c handler/int_142.c handler/int_143.c handler/int_144.c handler/int_145.c handler/int_146.c handler/int_147.c handler/int_148.c handler/int_149.c handler/int_150.c handler/int_151.c handler/int_152.c handler/int_153.c handler/int_154.c handler/int_155.c handler/int_156.c handler/int_157.c handler/int_158.c handler/int_159.c handler/int_160.c handler/int_161.c handler/int_162.c handler/int_163.c handler/int_164.c handler/int_165.c handler/int_166.c handler/int_167.c handler/int_168.c handler/int_169.c handler/int_170.c handler/int_171.c handler/int_172.c handler/int_173.c handler/int_174.c handler/int_175.c handler/int_176.c handler/int_177.c handler/int_178.c handler/int_179.c handler/int_180.c handler/int_181.c handler/int_182.c handler/int_183.c handler/int_184.c handler/int_185.c handler/int_186.c handler/int_187.c handler/int_188.c handler/int_189.c handler/int_190.c handler/int_191.c handler/int_192.c handler/int_193.c handler/int_194.c handler/int_195.c handler/int_196.c handler/int_197.c handler/int_198.c handler/int_199.c handler/int_200.c handler/int_201.c handler/int_202.c handler/int_203.c handler/int_204.c handler/int_205.c handler/int_206.c handler/int_207.c handler/int_208.c handler/int_209.c handler/int_210.c handler/int_211.c handler/int_212.c handler/int_213.c handler/int_214.c handler/int_215.c handler/int_216.c handler/int_217.c handler/int_218.c handler/int_219.c handler/int_220.c handler/int_221.c handler/int_222.c handler/int_223.c handler/int_224.c handler/int_225.c handler/int_226.c handler/int_227.c handler/int_228.c handler/int_229.c handler/int_230.c handler/int_231.c handler/int_232.c handler/int_233.c handler/int_234.c handler/int_235.c handler/int_236.c handler/int_237.c handler/int_238.c handler/int_239.c handler/int_240.c handler/int_241.c handler/int_242.c handler/int_243.c handler/int_244.c handler/int_245.c handler/int_246.c handler/int_247.c handler/int_248.c handler/int_249.c handler/int_250.c handler/int_251.c handler/int_252.c handler/int_253.c handler/int_254.c handler/int_255.c handler/int_defalut_handler_array.c

        src/pic.c src/interrupt_handler/timer.c
        src/interrupt_handler/general_protect.c
        src/interrupt_handler/keyboard.c
        src/syscall/print.c
        src/asm.s)

set_target_properties(CieOS PROPERTIES PREFIX "")
set_target_properties(CieOS PROPERTIES OUTPUT_NAME "kernel")
set_target_properties(CieOS PROPERTIES SUFFIX ".elf")

set(DIST_PATH "~/Projects/Qemu/test/kernel.elf")
add_custom_command(TARGET CieOS COMMAND ${CMAKE_COMMAND} -E copy $<TARGET_FILE:CieOS> ${DIST_PATH})