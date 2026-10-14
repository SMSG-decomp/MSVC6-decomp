ushort __cdecl debug_ivbclass_attributes(int base,c1_symbol *cls)

{
  ushort uVar1;
  byte bVar2;
  
  uVar1 = (ushort)g_cv_zero_attributes;
  bVar2 = class_base_access(base,cls);
  return (ushort)(bVar2 & 3) | uVar1 & 0xfffc;
}

