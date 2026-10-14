byte __fastcall class_type_needs_destructor_call(c1_type *type)

{
  byte bVar1;
  c1_symbol *cls;
  
  if ((type->code & 0x200) == 0) {
    if (((char)type->code < '\0') && ((type->base->code & 0x200) != 0)) {
      cls = (type->base->extra).cls;
    }
    else {
      cls = (c1_symbol *)0x0;
    }
  }
  else {
    cls = (type->extra).cls;
  }
  if ((cls->flags2 & 4) == 0) {
    tmpl_instantiate_if_needed(cls);
  }
  if (((((cls->detail).cls)->implicit_state41 & 0x10) == 0) &&
     ((((cls->detail).cls)->implicit_state43 & 0x10) == 0)) {
    bVar1 = class_type_needs_destructor_call_none();
    return bVar1;
  }
  if ((type->code & 0x200) != 0) {
    return (byte)~((((type->extra).cls)->detail).cls)->implicit_state41 >> 4 & 1;
  }
  if (((char)type->code < '\0') && ((type->base->code & 0x200) != 0)) {
    return (byte)~((((type->base->extra).cls)->detail).cls)->implicit_state41 >> 4 & 1;
  }
  return (byte)~*(byte *)(iRam00000024 + 0x41) >> 4 & 1;
}

