byte __cdecl class_has_special_member_kind(c1_symbol *cls,byte kind)

{
  byte bVar1;
  
  if ((cls->flags2 & 4) == 0) {
    tmpl_instantiate_if_needed(cls);
  }
  bVar1 = (byte)(1 << (kind & 0x1f));
  if ((((cls->detail).cls)->implicit_state41 & bVar1) != 0) {
    return 1;
  }
  return (((cls->detail).cls)->implicit_state43 & bVar1) != 0;
}

