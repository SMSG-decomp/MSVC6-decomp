void __cdecl c1xx_abort_if_running(void)

{
  if (g_compile_phase != 8) {
    if (g_compile_phase == 6) {
      return;
    }
    c1xx_set_phase(6);
    c1xx_abort_cleanup();
  }
  if (g_abort_semaphore != (HANDLE)0x0) {
    ReleaseSemaphore(g_abort_semaphore,1,(LPLONG)0x0);
  }
  Sleep(0);
  c1xx_raise_exit(0x8000);
}

