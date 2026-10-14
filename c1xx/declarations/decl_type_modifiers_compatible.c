int __thiscall
decl_type_modifiers_compatible(c1_declarator *d,ushort old_flags,ushort new_flags,c1_symbol *sym)

{
  c1_decl_record *pcVar1;
  
  if (old_flags != new_flags) {
    if ((((byte)old_flags ^ (byte)new_flags) & 7) != 0) {
      pcVar1 = d->decl;
      if (pcVar1 == (c1_decl_record *)0x0) {
        return 0;
      }
      if ((pcVar1->flags & 2) != 0) {
        return 0;
      }
      if ((pcVar1->type->code & 0x8f) != 0x85) {
        return 0;
      }
      old_flags = old_flags & 0xfff8;
      new_flags = new_flags & 0xfff8;
    }
    if (((old_flags ^ new_flags) & 0x1f) != 0) {
      return 0;
    }
    if (((old_flags ^ new_flags) & 0x3e0) != 0) {
      return 0;
    }
    if (((old_flags & 0x18) != 0) && ((new_flags & 0x18) != 0)) {
      return 0;
    }
  }
  return 1;
}

