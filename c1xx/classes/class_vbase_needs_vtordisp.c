char __cdecl class_vbase_needs_vtordisp(c1_symbol *cls,c1_symbol *vbase)

{
  char cVar1;
  
  cVar1 = class_bases_have_vtordisp_for_vbase(cls,vbase);
  if (cVar1 != '\0') {
    return '\x01';
  }
  if (g_class_vtordisp_off != '\0') {
    return '\0';
  }
  cVar1 = class_has_virtual_other_than_dtor(vbase);
  if (cVar1 == '\0') {
    return '\0';
  }
  cVar1 = class_ctor_and_dtor_are_implicit(cls);
  if (cVar1 != '\0') {
    return '\0';
  }
  cVar1 = class_not_ending_in_zero_sized_array(cls);
  if (cVar1 == '\0') {
    return '\0';
  }
  cVar1 = class_overrides_vbase_virtual(cls,vbase);
  return cVar1;
}

