ushort __cdecl debug_field_ivbclass(int pass,int base,c1_symbol *cls,ushort *out)

{
  ushort uVar1;
  
  if (pass == 2) {
    *out = 0x1402;
    uVar1 = debug_ivbclass_attributes(base,cls);
    out[1] = uVar1;
  }
  uVar1 = debug_field_vbclass_body(pass,out,(c1_symbol *)base,(c1_type *)cls);
  return uVar1;
}

