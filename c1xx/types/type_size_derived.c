int __fastcall type_size_derived(c1_type *t)

{
  c1_u32 cVar1;
  c1_type *t_00;
  ushort uVar2;
  int iVar3;
  
  if (-1 < (char)t->code) {
    iVar3 = type_size_scalar(t);
    return iVar3;
  }
  switch(t->code & 0x8f) {
  case 0x80:
  case 0x81:
  case 0x84:
  case 0x85:
  case 0x86:
switchD_1040d45d_caseD_80:
    return 4;
  case 0x82:
    t = t->base;
    if (-1 < (char)t->code) {
      iVar3 = type_size_scalar(t);
      return iVar3;
    }
    break;
  case 0x83:
    t_00 = t->base;
    if ((char)t_00->code < '\0') {
      uVar2 = t_00->code & 0x8f;
      if ((uVar2 == 0x86) || (uVar2 == 0x82)) {
        return 4;
      }
      if (uVar2 == 0x80) {
        return 4;
      }
      if (uVar2 == 0x8e) {
        iVar3 = type_member_pointer_size_kind(t_00);
        return iVar3;
      }
      if (uVar2 == 0x8a) {
        iVar3 = type_size_fragment(t_00);
        return iVar3;
      }
    }
    iVar3 = type_size_derived(t_00);
    if ((t_00->code & 0x8f) == 0x83) {
      return (t_00->extra).count * iVar3;
    }
    return iVar3;
  default:
switchD_1040d45d_caseD_87:
    return 0;
  case 0x8a:
switchD_1040d45d_caseD_8a:
    iVar3 = type_data_member_pointer_size(t);
    return iVar3;
  case 0x8e:
switchD_1040d45d_caseD_8e:
    iVar3 = type_member_pointer_size_kind(t);
    return iVar3;
  }
  switch(t->code & 0x8f) {
  case 0x80:
  case 0x82:
  case 0x84:
  case 0x86:
    goto switchD_1040d45d_caseD_80;
  default:
    goto switchD_1040d45d_caseD_87;
  case 0x83:
    cVar1 = (t->extra).count;
    iVar3 = type_size_derived(t);
    return iVar3 * cVar1;
  case 0x8a:
    goto switchD_1040d45d_caseD_8a;
  case 0x8e:
    goto switchD_1040d45d_caseD_8e;
  }
}

