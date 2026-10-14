int __cdecl class_best_inheritance_model(c1_symbol *cls)

{
  uint uVar1;
  
  if ((((cls->detail).cls)->layout_flags3b & 0x10) == 0) {
    uVar1 = class_is_single_inheritance((int)cls);
    return 2 - (uint)((char)uVar1 != '\0');
  }
  return 3;
}

