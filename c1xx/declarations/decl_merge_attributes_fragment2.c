void __thiscall decl_merge_attributes_fragment2(byte flags22,char changed,c1_symbol *sym,byte spec3)

{
  if ((flags22 & 4) == 0) {
    sym->flags22 = flags22 | 8;
    changed = '\x01';
  }
  if (((spec3 & 0x10) != 0) && ((sym->flags23 & 0x10) == 0)) {
    decl_merge_attributes_tail_thread(sym->flags23,sym);
    return;
  }
  if (changed != '\0') {
    sym->flags2 = sym->flags2 & 0xf7;
  }
  return;
}

