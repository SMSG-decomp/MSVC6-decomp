void __cdecl il_emit_symbol_with_mode(int kind,int symref,char mode)

{
  char cVar1;
  
  cVar1 = g_il_emit_mode;
  g_il_emit_mode = mode;
  il_emit_symbol(kind,(c1_symbol *)(symref + -8));
  g_il_emit_mode = cVar1;
  return;
}

