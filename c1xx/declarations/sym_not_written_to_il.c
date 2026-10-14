char __fastcall sym_not_written_to_il(c1_symbol *sym)

{
  byte bVar1;
  
  bVar1 = sym->kind & 0x1f;
  if ((bVar1 != 4) ||
     (((((sym->detail).cls)->flags3e & 2) == 0 && ((((sym->detail).cls)->flags3f & 0x80) == 0)))) {
    if ((bVar1 == 0x10) || (bVar1 == 0x11)) {
      il_emit_global_symbol_chain(&sym->kind);
    }
    else if (bVar1 != 0x1a) {
      if (bVar1 != 0x19) {
        return '\0';
      }
      (**(code **)(**(int **)sym->type + 0x24))();
      return '\x01';
    }
  }
  return '\x01';
}

