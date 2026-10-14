void __cdecl eh_finally_begin(void)

{
  il_emit_tuple(0x8e,(node *)0x0);
  g_seh_finally_depth = g_seh_finally_depth + 1;
  return;
}

