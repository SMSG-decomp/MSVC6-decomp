void __thiscall il_emitter_browse_reference_symbol(c1_il_emitter_browse *this,c1_symbol *sym)

{
  if (((g_compile_flags_cc & 0x8000) == 0) && ((sym->name->flags & 0x200000) == 0)) {
    browse_add_record(4,sym);
  }
  return;
}

