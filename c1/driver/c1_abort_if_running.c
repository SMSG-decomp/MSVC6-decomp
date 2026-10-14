void c1_abort_if_running(void)

{
  if (g_compile_phase != 8) {
    if (g_compile_phase == 6) {
      return;
    }
    c1_set_phase(6);
    c1_abort_cleanup();
  }
  if (g_abort_semaphore != (void *)0x0) {
    ReleaseSemaphore(g_abort_semaphore,1,(LPLONG)0x0);
  }
  Sleep(0);
  c1_raise_exit(0x8000);
}

