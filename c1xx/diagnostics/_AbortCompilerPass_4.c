void _AbortCompilerPass_4(void)

{
  DWORD DVar1;
  int iVar2;
  
  if ((g_abort_semaphore == (HANDLE)0x0) &&
     (g_abort_semaphore = CreateSemaphoreA((LPSECURITY_ATTRIBUTES)0x0,0,1,(LPCSTR)0x0),
     g_abort_semaphore != (HANDLE)0x0)) {
    g_abort_requested = 1;
    if ((g_compile_phase != 8) &&
       (DVar1 = WaitForSingleObject(g_abort_semaphore,4000), DVar1 == 0x102)) {
      diag_write_stderr("Compiler terminating.  Please wait.");
      iVar2 = 0;
      do {
        if ((g_compile_phase == 8) ||
           (DVar1 = WaitForSingleObject(g_abort_semaphore,2000), DVar1 != 0x102)) break;
        diag_write_stderr(".");
        iVar2 = iVar2 + 1;
      } while (iVar2 < 0x1e);
      diag_write_stderr(" Abort complete.\n");
      if (0x1d < iVar2) {
        ExitProcess(0x8000);
      }
    }
    CloseHandle(g_abort_semaphore);
    g_abort_semaphore = (HANDLE)0x0;
  }
  return;
}

