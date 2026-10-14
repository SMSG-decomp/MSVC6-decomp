c1_type * __fastcall conv_operand_type_for_common_type(c1_type *type)

{
  int iVar1;
  c1_type *pcVar2;
  
  iVar1 = type_category(type);
  if (iVar1 == 9) {
    pcVar2 = type_reference_to(type,'\0');
    return pcVar2;
  }
  if ((iVar1 == 0xb) && (((type->code & 0x8f) != 0x85 || ((((type->extra).cls)->flags5 & 1) != 0))))
  {
    pcVar2 = type_member_pointer_to_2(type,'\x01');
    return pcVar2;
  }
  return type;
}

