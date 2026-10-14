ushort __cdecl debug_field_vbclass(int pass,int base,int vbase,c1_symbol *cls,ushort *out)

{
  ushort uVar1;
  
  if (pass == 2) {
    *out = 0x1401;
    uVar1 = debug_member_field_attributes((c1_symbol *)base);
    out[1] = uVar1;
  }
  uVar1 = debug_field_vbclass_body(pass,out,(c1_symbol *)vbase,(c1_type *)cls);
  return uVar1;
}

