# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.29

rodos/tutorials/10-first-steps/CMakeFiles/fifo-sync.dir/fifo-sync.cpp.o: /home/ken/uni/bachelorarbeit/Bachelorarbeit-Code/sun-sensor-simulator/rodos/tutorials/10-first-steps/fifo-sync.cpp \
  /home/ken/uni/bachelorarbeit/Bachelorarbeit-Code/sun-sensor-simulator/rodos/api/application.h \
  /home/ken/uni/bachelorarbeit/Bachelorarbeit-Code/sun-sensor-simulator/rodos/api/barrier.h \
  /home/ken/uni/bachelorarbeit/Bachelorarbeit-Code/sun-sensor-simulator/rodos/api/checksumes.h \
  /home/ken/uni/bachelorarbeit/Bachelorarbeit-Code/sun-sensor-simulator/rodos/api/commbuffer.h \
  /home/ken/uni/bachelorarbeit/Bachelorarbeit-Code/sun-sensor-simulator/rodos/api/default-platform-parameter.h \
  /home/ken/uni/bachelorarbeit/Bachelorarbeit-Code/sun-sensor-simulator/rodos/api/fifo.h \
  /home/ken/uni/bachelorarbeit/Bachelorarbeit-Code/sun-sensor-simulator/rodos/api/gateway.h \
  /home/ken/uni/bachelorarbeit/Bachelorarbeit-Code/sun-sensor-simulator/rodos/api/gateway/gateway.h \
  /home/ken/uni/bachelorarbeit/Bachelorarbeit-Code/sun-sensor-simulator/rodos/api/gateway/linkinterface.h \
  /home/ken/uni/bachelorarbeit/Bachelorarbeit-Code/sun-sensor-simulator/rodos/api/gateway/linkinterfacecan.h \
  /home/ken/uni/bachelorarbeit/Bachelorarbeit-Code/sun-sensor-simulator/rodos/api/gateway/linkinterfaceshm.h \
  /home/ken/uni/bachelorarbeit/Bachelorarbeit-Code/sun-sensor-simulator/rodos/api/gateway/linkinterfaceuart.h \
  /home/ken/uni/bachelorarbeit/Bachelorarbeit-Code/sun-sensor-simulator/rodos/api/gateway/linkinterfaceudp.h \
  /home/ken/uni/bachelorarbeit/Bachelorarbeit-Code/sun-sensor-simulator/rodos/api/gateway/networkmessage.h \
  /home/ken/uni/bachelorarbeit/Bachelorarbeit-Code/sun-sensor-simulator/rodos/api/gateway/router.h \
  /home/ken/uni/bachelorarbeit/Bachelorarbeit-Code/sun-sensor-simulator/rodos/api/hal.h \
  /home/ken/uni/bachelorarbeit/Bachelorarbeit-Code/sun-sensor-simulator/rodos/api/hal/genericIO.h \
  /home/ken/uni/bachelorarbeit/Bachelorarbeit-Code/sun-sensor-simulator/rodos/api/hal/hal_adc.h \
  /home/ken/uni/bachelorarbeit/Bachelorarbeit-Code/sun-sensor-simulator/rodos/api/hal/hal_can.h \
  /home/ken/uni/bachelorarbeit/Bachelorarbeit-Code/sun-sensor-simulator/rodos/api/hal/hal_gpio.h \
  /home/ken/uni/bachelorarbeit/Bachelorarbeit-Code/sun-sensor-simulator/rodos/api/hal/hal_i2c.h \
  /home/ken/uni/bachelorarbeit/Bachelorarbeit-Code/sun-sensor-simulator/rodos/api/hal/hal_pwm.h \
  /home/ken/uni/bachelorarbeit/Bachelorarbeit-Code/sun-sensor-simulator/rodos/api/hal/hal_sharedmemory.h \
  /home/ken/uni/bachelorarbeit/Bachelorarbeit-Code/sun-sensor-simulator/rodos/api/hal/hal_spi.h \
  /home/ken/uni/bachelorarbeit/Bachelorarbeit-Code/sun-sensor-simulator/rodos/api/hal/hal_uart.h \
  /home/ken/uni/bachelorarbeit/Bachelorarbeit-Code/sun-sensor-simulator/rodos/api/hal/udp.h \
  /home/ken/uni/bachelorarbeit/Bachelorarbeit-Code/sun-sensor-simulator/rodos/api/hostinfos.h \
  /home/ken/uni/bachelorarbeit/Bachelorarbeit-Code/sun-sensor-simulator/rodos/api/initiator.h \
  /home/ken/uni/bachelorarbeit/Bachelorarbeit-Code/sun-sensor-simulator/rodos/api/listelement.h \
  /home/ken/uni/bachelorarbeit/Bachelorarbeit-Code/sun-sensor-simulator/rodos/api/misc-rodos-funcs.h \
  /home/ken/uni/bachelorarbeit/Bachelorarbeit-Code/sun-sensor-simulator/rodos/api/netmsginfo.h \
  /home/ken/uni/bachelorarbeit/Bachelorarbeit-Code/sun-sensor-simulator/rodos/api/putter.h \
  /home/ken/uni/bachelorarbeit/Bachelorarbeit-Code/sun-sensor-simulator/rodos/api/reserved_application_ids.h \
  /home/ken/uni/bachelorarbeit/Bachelorarbeit-Code/sun-sensor-simulator/rodos/api/reserved_topic_ids.h \
  /home/ken/uni/bachelorarbeit/Bachelorarbeit-Code/sun-sensor-simulator/rodos/api/rodos-assert.h \
  /home/ken/uni/bachelorarbeit/Bachelorarbeit-Code/sun-sensor-simulator/rodos/api/rodos-atomic.h \
  /home/ken/uni/bachelorarbeit/Bachelorarbeit-Code/sun-sensor-simulator/rodos/api/rodos-debug.h \
  /home/ken/uni/bachelorarbeit/Bachelorarbeit-Code/sun-sensor-simulator/rodos/api/rodos-errorcodes.h \
  /home/ken/uni/bachelorarbeit/Bachelorarbeit-Code/sun-sensor-simulator/rodos/api/rodos-semaphore.h \
  /home/ken/uni/bachelorarbeit/Bachelorarbeit-Code/sun-sensor-simulator/rodos/api/rodos-version.h \
  /home/ken/uni/bachelorarbeit/Bachelorarbeit-Code/sun-sensor-simulator/rodos/api/rodos.h \
  /home/ken/uni/bachelorarbeit/Bachelorarbeit-Code/sun-sensor-simulator/rodos/api/stream-bytesex.h \
  /home/ken/uni/bachelorarbeit/Bachelorarbeit-Code/sun-sensor-simulator/rodos/api/string_pico.h \
  /home/ken/uni/bachelorarbeit/Bachelorarbeit-Code/sun-sensor-simulator/rodos/api/subscriber.h \
  /home/ken/uni/bachelorarbeit/Bachelorarbeit-Code/sun-sensor-simulator/rodos/api/thread.h \
  /home/ken/uni/bachelorarbeit/Bachelorarbeit-Code/sun-sensor-simulator/rodos/api/timeevent.h \
  /home/ken/uni/bachelorarbeit/Bachelorarbeit-Code/sun-sensor-simulator/rodos/api/timemodel.h \
  /home/ken/uni/bachelorarbeit/Bachelorarbeit-Code/sun-sensor-simulator/rodos/api/timepoints.h \
  /home/ken/uni/bachelorarbeit/Bachelorarbeit-Code/sun-sensor-simulator/rodos/api/topic.h \
  /home/ken/uni/bachelorarbeit/Bachelorarbeit-Code/sun-sensor-simulator/rodos/api/yprintf.h \
  /home/ken/uni/bachelorarbeit/Bachelorarbeit-Code/sun-sensor-simulator/rodos/src/bare-metal/linux-x86/hw_udp.h \
  /home/ken/uni/bachelorarbeit/Bachelorarbeit-Code/sun-sensor-simulator/rodos/src/bare-metal/linux-x86/platform-parameter.h \
  /home/ken/uni/bachelorarbeit/Bachelorarbeit-Code/sun-sensor-simulator/rodos/support/support-libs/s3p-code.h \
  /home/ken/uni/bachelorarbeit/Bachelorarbeit-Code/sun-sensor-simulator/rodos/support/support-libs/s3p-synchronous-interface.h \
  /usr/include/asm-generic/bitsperlong.h \
  /usr/include/asm-generic/errno-base.h \
  /usr/include/asm-generic/errno.h \
  /usr/include/asm-generic/posix_types.h \
  /usr/include/asm-generic/socket.h \
  /usr/include/asm-generic/sockios.h \
  /usr/include/asm/bitsperlong.h \
  /usr/include/asm/errno.h \
  /usr/include/asm/posix_types.h \
  /usr/include/asm/posix_types_32.h \
  /usr/include/asm/socket.h \
  /usr/include/asm/sockios.h \
  /usr/include/asm/unistd.h \
  /usr/include/asm/unistd_32.h \
  /usr/include/bits/atomic_wide_counter.h \
  /usr/include/bits/byteswap.h \
  /usr/include/bits/confname.h \
  /usr/include/bits/cpu-set.h \
  /usr/include/bits/endian.h \
  /usr/include/bits/endianness.h \
  /usr/include/bits/environments.h \
  /usr/include/bits/errno.h \
  /usr/include/bits/getopt_core.h \
  /usr/include/bits/getopt_posix.h \
  /usr/include/bits/in.h \
  /usr/include/bits/libc-header-start.h \
  /usr/include/bits/local_lim.h \
  /usr/include/bits/long-double.h \
  /usr/include/bits/netdb.h \
  /usr/include/bits/posix1_lim.h \
  /usr/include/bits/posix2_lim.h \
  /usr/include/bits/posix_opt.h \
  /usr/include/bits/pthread_stack_min-dynamic.h \
  /usr/include/bits/pthreadtypes-arch.h \
  /usr/include/bits/pthreadtypes.h \
  /usr/include/bits/sched.h \
  /usr/include/bits/select.h \
  /usr/include/bits/setjmp.h \
  /usr/include/bits/sockaddr.h \
  /usr/include/bits/socket.h \
  /usr/include/bits/socket_type.h \
  /usr/include/bits/stdint-intn.h \
  /usr/include/bits/stdint-least.h \
  /usr/include/bits/stdint-uintn.h \
  /usr/include/bits/struct_mutex.h \
  /usr/include/bits/struct_rwlock.h \
  /usr/include/bits/syscall.h \
  /usr/include/bits/thread-shared-types.h \
  /usr/include/bits/time.h \
  /usr/include/bits/time64.h \
  /usr/include/bits/timesize.h \
  /usr/include/bits/timex.h \
  /usr/include/bits/types.h \
  /usr/include/bits/types/__locale_t.h \
  /usr/include/bits/types/__sigset_t.h \
  /usr/include/bits/types/__sigval_t.h \
  /usr/include/bits/types/clock_t.h \
  /usr/include/bits/types/clockid_t.h \
  /usr/include/bits/types/error_t.h \
  /usr/include/bits/types/locale_t.h \
  /usr/include/bits/types/sigevent_t.h \
  /usr/include/bits/types/sigset_t.h \
  /usr/include/bits/types/struct___jmp_buf_tag.h \
  /usr/include/bits/types/struct_iovec.h \
  /usr/include/bits/types/struct_itimerspec.h \
  /usr/include/bits/types/struct_osockaddr.h \
  /usr/include/bits/types/struct_sched_param.h \
  /usr/include/bits/types/struct_timespec.h \
  /usr/include/bits/types/struct_timeval.h \
  /usr/include/bits/types/struct_tm.h \
  /usr/include/bits/types/time_t.h \
  /usr/include/bits/types/timer_t.h \
  /usr/include/bits/typesizes.h \
  /usr/include/bits/uintn-identity.h \
  /usr/include/bits/uio_lim.h \
  /usr/include/bits/unistd_ext.h \
  /usr/include/bits/wchar.h \
  /usr/include/bits/wordsize.h \
  /usr/include/bits/xopen_lim.h \
  /usr/include/c++/13.2.1/atomic \
  /usr/include/c++/13.2.1/bits/atomic_base.h \
  /usr/include/c++/13.2.1/bits/atomic_lockfree_defines.h \
  /usr/include/c++/13.2.1/bits/atomic_wait.h \
  /usr/include/c++/13.2.1/bits/cpp_type_traits.h \
  /usr/include/c++/13.2.1/bits/exception.h \
  /usr/include/c++/13.2.1/bits/exception_defines.h \
  /usr/include/c++/13.2.1/bits/functexcept.h \
  /usr/include/c++/13.2.1/bits/functional_hash.h \
  /usr/include/c++/13.2.1/bits/hash_bytes.h \
  /usr/include/c++/13.2.1/bits/move.h \
  /usr/include/c++/13.2.1/bits/std_mutex.h \
  /usr/include/c++/13.2.1/cerrno \
  /usr/include/c++/13.2.1/climits \
  /usr/include/c++/13.2.1/cstddef \
  /usr/include/c++/13.2.1/cstdint \
  /usr/include/c++/13.2.1/ext/numeric_traits.h \
  /usr/include/c++/13.2.1/ext/type_traits.h \
  /usr/include/c++/13.2.1/new \
  /usr/include/c++/13.2.1/pstl/pstl_config.h \
  /usr/include/c++/13.2.1/type_traits \
  /usr/include/c++/13.2.1/x86_64-pc-linux-gnu/32/bits/c++config.h \
  /usr/include/c++/13.2.1/x86_64-pc-linux-gnu/32/bits/cpu_defines.h \
  /usr/include/c++/13.2.1/x86_64-pc-linux-gnu/32/bits/gthr-default.h \
  /usr/include/c++/13.2.1/x86_64-pc-linux-gnu/32/bits/gthr.h \
  /usr/include/c++/13.2.1/x86_64-pc-linux-gnu/32/bits/os_defines.h \
  /usr/include/endian.h \
  /usr/include/errno.h \
  /usr/include/features-time64.h \
  /usr/include/features.h \
  /usr/include/gnu/stubs-32.h \
  /usr/include/gnu/stubs.h \
  /usr/include/limits.h \
  /usr/include/linux/close_range.h \
  /usr/include/linux/errno.h \
  /usr/include/linux/limits.h \
  /usr/include/linux/posix_types.h \
  /usr/include/linux/stddef.h \
  /usr/include/netdb.h \
  /usr/include/netinet/in.h \
  /usr/include/pthread.h \
  /usr/include/rpc/netdb.h \
  /usr/include/sched.h \
  /usr/include/stdc-predef.h \
  /usr/include/stdint.h \
  /usr/include/sys/cdefs.h \
  /usr/include/sys/select.h \
  /usr/include/sys/socket.h \
  /usr/include/sys/syscall.h \
  /usr/include/sys/types.h \
  /usr/include/syscall.h \
  /usr/include/time.h \
  /usr/include/unistd.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/13.2.1/include/limits.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/13.2.1/include/stdarg.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/13.2.1/include/stddef.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/13.2.1/include/stdint.h \
  /usr/lib/gcc/x86_64-pc-linux-gnu/13.2.1/include/syslimits.h


/usr/include/unistd.h:

/usr/include/sys/syscall.h:

/usr/include/sys/select.h:

/usr/include/sys/socket.h:

/usr/include/sys/cdefs.h:

/usr/include/sched.h:

/usr/include/rpc/netdb.h:

/usr/include/linux/posix_types.h:

/usr/include/stdint.h:

/usr/include/linux/limits.h:

/usr/include/limits.h:

/usr/include/gnu/stubs-32.h:

/usr/include/c++/13.2.1/x86_64-pc-linux-gnu/32/bits/os_defines.h:

/usr/include/c++/13.2.1/x86_64-pc-linux-gnu/32/bits/gthr.h:

/usr/include/c++/13.2.1/x86_64-pc-linux-gnu/32/bits/gthr-default.h:

/usr/include/c++/13.2.1/x86_64-pc-linux-gnu/32/bits/c++config.h:

/usr/include/c++/13.2.1/pstl/pstl_config.h:

/usr/include/c++/13.2.1/new:

/usr/lib/gcc/x86_64-pc-linux-gnu/13.2.1/include/limits.h:

/usr/include/c++/13.2.1/ext/type_traits.h:

/usr/include/c++/13.2.1/ext/numeric_traits.h:

/usr/include/c++/13.2.1/cstddef:

/usr/include/c++/13.2.1/climits:

/usr/include/c++/13.2.1/bits/move.h:

/usr/include/linux/errno.h:

/usr/include/c++/13.2.1/bits/hash_bytes.h:

/usr/include/linux/stddef.h:

/usr/include/c++/13.2.1/bits/functional_hash.h:

/usr/include/c++/13.2.1/bits/functexcept.h:

/usr/include/c++/13.2.1/bits/exception_defines.h:

/usr/include/c++/13.2.1/bits/cpp_type_traits.h:

/usr/include/features-time64.h:

/usr/include/c++/13.2.1/bits/atomic_lockfree_defines.h:

/usr/include/c++/13.2.1/atomic:

/usr/include/bits/unistd_ext.h:

/usr/include/bits/uintn-identity.h:

/usr/include/c++/13.2.1/bits/std_mutex.h:

/usr/include/bits/typesizes.h:

/usr/include/asm-generic/errno-base.h:

/usr/include/bits/wchar.h:

/usr/include/asm-generic/bitsperlong.h:

/home/ken/uni/bachelorarbeit/Bachelorarbeit-Code/sun-sensor-simulator/rodos/api/gateway/gateway.h:

/home/ken/uni/bachelorarbeit/Bachelorarbeit-Code/sun-sensor-simulator/rodos/support/support-libs/s3p-code.h:

/home/ken/uni/bachelorarbeit/Bachelorarbeit-Code/sun-sensor-simulator/rodos/api/yprintf.h:

/usr/include/bits/types/struct_iovec.h:

/usr/include/bits/struct_mutex.h:

/home/ken/uni/bachelorarbeit/Bachelorarbeit-Code/sun-sensor-simulator/rodos/support/support-libs/s3p-synchronous-interface.h:

/home/ken/uni/bachelorarbeit/Bachelorarbeit-Code/sun-sensor-simulator/rodos/api/hal/hal_spi.h:

/home/ken/uni/bachelorarbeit/Bachelorarbeit-Code/sun-sensor-simulator/rodos/api/timeevent.h:

/usr/include/bits/xopen_lim.h:

/home/ken/uni/bachelorarbeit/Bachelorarbeit-Code/sun-sensor-simulator/rodos/api/hal/hal_uart.h:

/home/ken/uni/bachelorarbeit/Bachelorarbeit-Code/sun-sensor-simulator/rodos/api/thread.h:

/usr/include/netinet/in.h:

/usr/include/netdb.h:

/home/ken/uni/bachelorarbeit/Bachelorarbeit-Code/sun-sensor-simulator/rodos/api/subscriber.h:

/usr/include/syscall.h:

/usr/include/asm-generic/errno.h:

/usr/lib/gcc/x86_64-pc-linux-gnu/13.2.1/include/syslimits.h:

/home/ken/uni/bachelorarbeit/Bachelorarbeit-Code/sun-sensor-simulator/rodos/api/string_pico.h:

/usr/include/bits/local_lim.h:

/usr/include/bits/netdb.h:

/home/ken/uni/bachelorarbeit/Bachelorarbeit-Code/sun-sensor-simulator/rodos/api/rodos-atomic.h:

/usr/include/bits/libc-header-start.h:

/usr/include/stdc-predef.h:

/usr/include/asm-generic/posix_types.h:

/usr/include/c++/13.2.1/cerrno:

/usr/include/bits/types/__sigset_t.h:

/home/ken/uni/bachelorarbeit/Bachelorarbeit-Code/sun-sensor-simulator/rodos/api/rodos-assert.h:

/usr/include/bits/posix_opt.h:

/usr/include/bits/atomic_wide_counter.h:

/usr/include/bits/types/clockid_t.h:

/usr/include/bits/types/timer_t.h:

/usr/include/sys/types.h:

/home/ken/uni/bachelorarbeit/Bachelorarbeit-Code/sun-sensor-simulator/rodos/api/reserved_topic_ids.h:

/usr/include/bits/endian.h:

/usr/include/bits/timesize.h:

/home/ken/uni/bachelorarbeit/Bachelorarbeit-Code/sun-sensor-simulator/rodos/api/misc-rodos-funcs.h:

/home/ken/uni/bachelorarbeit/Bachelorarbeit-Code/sun-sensor-simulator/rodos/api/gateway/linkinterfacecan.h:

/home/ken/uni/bachelorarbeit/Bachelorarbeit-Code/sun-sensor-simulator/rodos/api/topic.h:

/usr/include/bits/select.h:

/usr/include/bits/wordsize.h:

/home/ken/uni/bachelorarbeit/Bachelorarbeit-Code/sun-sensor-simulator/rodos/api/gateway/linkinterfaceuart.h:

/usr/include/pthread.h:

/home/ken/uni/bachelorarbeit/Bachelorarbeit-Code/sun-sensor-simulator/rodos/api/netmsginfo.h:

/usr/include/bits/types/__sigval_t.h:

/home/ken/uni/bachelorarbeit/Bachelorarbeit-Code/sun-sensor-simulator/rodos/tutorials/10-first-steps/fifo-sync.cpp:

/home/ken/uni/bachelorarbeit/Bachelorarbeit-Code/sun-sensor-simulator/rodos/api/gateway/linkinterfaceshm.h:

/home/ken/uni/bachelorarbeit/Bachelorarbeit-Code/sun-sensor-simulator/rodos/api/rodos-semaphore.h:

/home/ken/uni/bachelorarbeit/Bachelorarbeit-Code/sun-sensor-simulator/rodos/api/timemodel.h:

/home/ken/uni/bachelorarbeit/Bachelorarbeit-Code/sun-sensor-simulator/rodos/api/rodos-errorcodes.h:

/usr/lib/gcc/x86_64-pc-linux-gnu/13.2.1/include/stdint.h:

/usr/include/asm-generic/sockios.h:

/usr/include/bits/types/sigset_t.h:

/usr/include/asm/unistd_32.h:

/home/ken/uni/bachelorarbeit/Bachelorarbeit-Code/sun-sensor-simulator/rodos/api/hal/hal_can.h:

/home/ken/uni/bachelorarbeit/Bachelorarbeit-Code/sun-sensor-simulator/rodos/api/checksumes.h:

/home/ken/uni/bachelorarbeit/Bachelorarbeit-Code/sun-sensor-simulator/rodos/api/fifo.h:

/usr/lib/gcc/x86_64-pc-linux-gnu/13.2.1/include/stdarg.h:

/home/ken/uni/bachelorarbeit/Bachelorarbeit-Code/sun-sensor-simulator/rodos/api/hal/hal_pwm.h:

/usr/include/errno.h:

/home/ken/uni/bachelorarbeit/Bachelorarbeit-Code/sun-sensor-simulator/rodos/api/reserved_application_ids.h:

/home/ken/uni/bachelorarbeit/Bachelorarbeit-Code/sun-sensor-simulator/rodos/api/hostinfos.h:

/usr/include/bits/types/locale_t.h:

/home/ken/uni/bachelorarbeit/Bachelorarbeit-Code/sun-sensor-simulator/rodos/api/rodos-debug.h:

/usr/include/c++/13.2.1/cstdint:

/usr/include/asm/socket.h:

/usr/include/c++/13.2.1/bits/exception.h:

/usr/include/bits/setjmp.h:

/home/ken/uni/bachelorarbeit/Bachelorarbeit-Code/sun-sensor-simulator/rodos/api/stream-bytesex.h:

/home/ken/uni/bachelorarbeit/Bachelorarbeit-Code/sun-sensor-simulator/rodos/api/barrier.h:

/usr/include/bits/types/struct___jmp_buf_tag.h:

/home/ken/uni/bachelorarbeit/Bachelorarbeit-Code/sun-sensor-simulator/rodos/api/gateway/router.h:

/home/ken/uni/bachelorarbeit/Bachelorarbeit-Code/sun-sensor-simulator/rodos/api/hal.h:

/usr/include/endian.h:

/home/ken/uni/bachelorarbeit/Bachelorarbeit-Code/sun-sensor-simulator/rodos/api/timepoints.h:

/home/ken/uni/bachelorarbeit/Bachelorarbeit-Code/sun-sensor-simulator/rodos/api/hal/hal_adc.h:

/usr/include/asm/sockios.h:

/home/ken/uni/bachelorarbeit/Bachelorarbeit-Code/sun-sensor-simulator/rodos/api/rodos.h:

/usr/include/bits/pthread_stack_min-dynamic.h:

/home/ken/uni/bachelorarbeit/Bachelorarbeit-Code/sun-sensor-simulator/rodos/api/rodos-version.h:

/home/ken/uni/bachelorarbeit/Bachelorarbeit-Code/sun-sensor-simulator/rodos/api/application.h:

/home/ken/uni/bachelorarbeit/Bachelorarbeit-Code/sun-sensor-simulator/rodos/api/hal/udp.h:

/home/ken/uni/bachelorarbeit/Bachelorarbeit-Code/sun-sensor-simulator/rodos/api/listelement.h:

/usr/include/c++/13.2.1/bits/atomic_base.h:

/usr/include/bits/uio_lim.h:

/home/ken/uni/bachelorarbeit/Bachelorarbeit-Code/sun-sensor-simulator/rodos/api/hal/hal_sharedmemory.h:

/usr/include/bits/types/struct_tm.h:

/home/ken/uni/bachelorarbeit/Bachelorarbeit-Code/sun-sensor-simulator/rodos/api/gateway/networkmessage.h:

/home/ken/uni/bachelorarbeit/Bachelorarbeit-Code/sun-sensor-simulator/rodos/api/hal/genericIO.h:

/usr/include/bits/confname.h:

/home/ken/uni/bachelorarbeit/Bachelorarbeit-Code/sun-sensor-simulator/rodos/api/gateway/linkinterfaceudp.h:

/home/ken/uni/bachelorarbeit/Bachelorarbeit-Code/sun-sensor-simulator/rodos/api/initiator.h:

/home/ken/uni/bachelorarbeit/Bachelorarbeit-Code/sun-sensor-simulator/rodos/api/hal/hal_i2c.h:

/usr/include/bits/sched.h:

/usr/include/time.h:

/home/ken/uni/bachelorarbeit/Bachelorarbeit-Code/sun-sensor-simulator/rodos/api/putter.h:

/usr/include/bits/socket.h:

/usr/include/bits/stdint-uintn.h:

/usr/include/asm-generic/socket.h:

/usr/include/asm/bitsperlong.h:

/usr/include/asm/posix_types.h:

/home/ken/uni/bachelorarbeit/Bachelorarbeit-Code/sun-sensor-simulator/rodos/api/default-platform-parameter.h:

/usr/include/bits/time.h:

/usr/include/asm/posix_types_32.h:

/usr/lib/gcc/x86_64-pc-linux-gnu/13.2.1/include/stddef.h:

/usr/include/asm/unistd.h:

/usr/include/bits/byteswap.h:

/usr/include/bits/cpu-set.h:

/usr/include/features.h:

/home/ken/uni/bachelorarbeit/Bachelorarbeit-Code/sun-sensor-simulator/rodos/api/gateway.h:

/usr/include/bits/endianness.h:

/usr/include/bits/environments.h:

/usr/include/bits/getopt_core.h:

/usr/include/bits/types.h:

/usr/include/bits/getopt_posix.h:

/usr/include/bits/in.h:

/usr/include/bits/types/struct_sched_param.h:

/usr/include/c++/13.2.1/bits/atomic_wait.h:

/home/ken/uni/bachelorarbeit/Bachelorarbeit-Code/sun-sensor-simulator/rodos/api/hal/hal_gpio.h:

/usr/include/bits/long-double.h:

/usr/include/bits/posix1_lim.h:

/usr/include/bits/posix2_lim.h:

/usr/include/gnu/stubs.h:

/usr/include/bits/pthreadtypes-arch.h:

/home/ken/uni/bachelorarbeit/Bachelorarbeit-Code/sun-sensor-simulator/rodos/src/bare-metal/linux-x86/platform-parameter.h:

/home/ken/uni/bachelorarbeit/Bachelorarbeit-Code/sun-sensor-simulator/rodos/api/gateway/linkinterface.h:

/usr/include/bits/pthreadtypes.h:

/home/ken/uni/bachelorarbeit/Bachelorarbeit-Code/sun-sensor-simulator/rodos/src/bare-metal/linux-x86/hw_udp.h:

/usr/include/bits/sockaddr.h:

/usr/include/bits/socket_type.h:

/usr/include/asm/errno.h:

/usr/include/bits/types/struct_osockaddr.h:

/usr/include/linux/close_range.h:

/usr/include/bits/stdint-intn.h:

/usr/include/bits/types/error_t.h:

/usr/include/bits/stdint-least.h:

/usr/include/c++/13.2.1/x86_64-pc-linux-gnu/32/bits/cpu_defines.h:

/usr/include/bits/types/time_t.h:

/usr/include/bits/syscall.h:

/usr/include/bits/thread-shared-types.h:

/usr/include/bits/time64.h:

/usr/include/bits/errno.h:

/usr/include/bits/timex.h:

/usr/include/bits/types/__locale_t.h:

/usr/include/c++/13.2.1/type_traits:

/usr/include/bits/types/clock_t.h:

/usr/include/bits/types/sigevent_t.h:

/usr/include/bits/struct_rwlock.h:

/usr/include/bits/types/struct_itimerspec.h:

/home/ken/uni/bachelorarbeit/Bachelorarbeit-Code/sun-sensor-simulator/rodos/api/commbuffer.h:

/usr/include/bits/types/struct_timespec.h:

/usr/include/bits/types/struct_timeval.h:
