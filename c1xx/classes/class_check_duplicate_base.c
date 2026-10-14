c1_u8 __cdecl class_check_duplicate_base(char is_virtual,c1_symbol *base,c1_symbol *cls)

{
  c1_symbol *pcVar1;
  int iVar2;
  c1_symbol *pcVar3;
  
  pcVar1 = cls;
  iVar2 = class_base_overlap_kind(is_virtual,base,cls,'\x01',&cls);
  switch(iVar2) {
  case 0:
    goto switchD_1043920e_caseD_0;
  case 1:
    diag_error(500,pcVar1,base);
    return '\0';
  case 2:
    pcVar3 = base;
    base = cls;
    break;
  case 3:
    pcVar3 = cls;
    break;
  default:
    return '\0';
  }
  diag_error(0x248,pcVar1,pcVar3,base);
switchD_1043920e_caseD_0:
  return '\x01';
}

