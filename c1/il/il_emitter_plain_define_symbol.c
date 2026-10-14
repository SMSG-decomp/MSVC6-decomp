void __thiscall il_emitter_plain_define_symbol(c1_il_emitter *this,c1_symbol *sym)

{
  uint *puVar1;
  
  if (g_emitter_region_mode == 3) {
    puVar1 = &sym->name->flags;
    *puVar1 = *puVar1 | 0x200000;
  }
  return;
}

