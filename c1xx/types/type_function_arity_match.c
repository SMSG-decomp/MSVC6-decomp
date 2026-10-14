uint __cdecl type_function_arity_match(c1_type *fn_type,uint arg_count)

{
  uint uVar1;
  bool bVar2;
  
  if ((fn_type->flags & 0x4000) != 0) {
    return (-(uint)(arg_count != 0) & 0xfffffffe) + 2;
  }
  uVar1 = ((fn_type->extra).params)->list->count;
  bVar2 = (fn_type->flags & 0x8000) != 0;
  if (bVar2) {
    uVar1 = uVar1 - 1;
  }
  if (arg_count == uVar1) {
    return 2;
  }
  if (arg_count <= uVar1) {
    return 2 - (((fn_type->extra).params)->default_count + arg_count < uVar1);
  }
  return -(uint)bVar2 & 3;
}

