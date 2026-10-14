byte __cdecl type_member_pointers_same_null(c1_type *a,c1_type *b)

{
  uint uVar1;
  uint uVar2;
  
  uVar1 = type_member_pointer_class_has_vfptr(a);
  uVar2 = type_member_pointer_class_has_vfptr(b);
  return (char)uVar1 == (char)uVar2;
}

