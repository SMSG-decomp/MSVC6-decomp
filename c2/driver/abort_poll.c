int abort_poll(void)

{
  int extraout_EAX;
  
  if (g_abort_requested == 0) {
    return 0;
  }
  if (g_backend_state != 4) {
    if (g_backend_state == 3) {
      return 3;
    }
    g_backend_state = 3;
    abort_cleanup();
    if (g_backend_state != 4) {
      ice_fatal("E:\\8168\\vc98\\p2\\src\\P2\\x86\\dll.c",0xc6);
    }
  }
  if (g_abort_semaphore != (HANDLE)0x0) {
    ReleaseSemaphore(g_abort_semaphore,1,(LPLONG)0x0);
  }
  Sleep(0);
  backend_cleanup(0);
  RaiseException(0xe0005032,0xc0000025,1,(ULONG_PTR *)&stack0xfffffffc);
  return extraout_EAX;
}

