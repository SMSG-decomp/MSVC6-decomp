void c1_abort_cleanup(void)

{
  include_close_all();
  pch_finish_files();
  il_emitters_discard();
  pdb_session_close(&g_pdb);
  g_last_in_batch = 1;
  if (g_pdb_gi != (c1_pdb_state *)0x0) {
    pdb_session_close(g_pdb_gi);
  }
  c1_cleanup();
  g_compile_phase = 8;
  if (g_abort_requested == 0) {
    return;
  }
  g_compile_phase = 8;
  if (g_abort_semaphore != (void *)0x0) {
    ReleaseSemaphore(g_abort_semaphore,1,(LPLONG)0x0);
  }
  Sleep(0);
  c1_raise_exit(0x8000);
}

