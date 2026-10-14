void __cdecl stderr_to_stdout(void)

{
  if (g_merge_stderr != 0) {
    _dup2(1,2);
  }
  return;
}

