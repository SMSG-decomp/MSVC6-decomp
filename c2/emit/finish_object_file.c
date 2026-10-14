void finish_object_file(void)

{
  (*g_hook_cv_finish_globals)();
  (*g_hook_finish_object)();
  if (g_opt_ZX == 0) {
    return;
  }
  OCRelease(g_enc_funcsyms);
  return;
}

