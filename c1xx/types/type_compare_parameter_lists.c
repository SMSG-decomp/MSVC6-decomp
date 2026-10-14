uint __cdecl type_compare_parameter_lists(int *a,int *b)

{
  int *piVar1;
  c1_type *a_00;
  int iVar2;
  uint uVar3;
  c1_type *b_00;
  int *piVar4;
  int iVar5;
  
  iVar5 = *a;
  if (iVar5 == *b) {
    piVar1 = a + 2;
    a_00 = (c1_type *)*piVar1;
    b_00 = (c1_type *)b[2];
    if (iVar5 < 1) {
      return 0;
    }
    piVar4 = piVar1;
    while( true ) {
      iVar5 = iVar5 + -1;
      iVar2 = type_compare_template_instance_chain(a_00,b_00);
      if (iVar2 == 2) break;
      a_00 = (c1_type *)piVar4[1];
      b_00 = *(c1_type **)((int)(b + 2) + (4 - (int)piVar1) + (int)piVar4);
      piVar4 = piVar4 + 1;
      if (iVar5 < 1) {
        uVar3 = type_compare_parameter_lists_tail();
        return uVar3;
      }
    }
  }
  return 2;
}

