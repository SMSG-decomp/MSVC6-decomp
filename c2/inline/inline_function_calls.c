void __fastcall inline_function_calls(c2_function *fn)

{
  c2_symbol_chunk *pcVar1;
  int budget;
  c2_symbol *sym;
  
  arena_reset(4);
  g_inline_total_size = (int)(short)fn->fsym->inline_size;
  budget = g_inline_total_size * 2;
  if (budget < 1000) {
    budget = 1000;
  }
  else if (35000 < budget) {
    budget = 35000;
  }
  g_inlining_active = 1;
  budget = inline_expand_calls(fn,1,budget,0);
  g_inlining_active = 0;
  arena_reset(4);
  g_cur_function_line_base = fn->line_base;
  pcVar1 = g_symbol_chunks;
  if ((0 < budget) || (g_opt_global != 0)) {
    for (; pcVar1 != (c2_symbol_chunk *)0x0; pcVar1 = pcVar1->next) {
      sym = pcVar1->syms;
      if (sym < pcVar1->cursor) {
        do {
          if (sym->cls != '\x10') {
            sym->flags5 = sym->flags5 & 0x7d;
          }
          sym = sym + 1;
        } while (sym < pcVar1->cursor);
      }
    }
  }
  return;
}

