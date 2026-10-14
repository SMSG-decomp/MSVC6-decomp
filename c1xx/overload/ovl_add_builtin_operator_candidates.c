void __thiscall
ovl_add_builtin_operator_candidates(void *frame,char *rows,c1_node *left,c1_node *right,int *count)

{
  c1_builtin_operator_row *pcVar1;
  char cVar2;
  c1_type *pattern;
  c1_type *pattern_00;
  c1_type *pcVar3;
  char cVar4;
  int iVar5;
  c1_builtin_operand_iter local_50;
  c1_builtin_operand_iter local_28;
  
  if (rows != (char *)0x0) {
    cVar2 = *rows;
    do {
      pattern = ((c1_builtin_operator_row *)rows)->right;
      pattern_00 = ((c1_builtin_operator_row *)rows)->left;
      if ((right != (c1_node *)0x0) == (pattern != (c1_type *)0x0)) {
        if (pattern == (c1_type *)0x0) {
          ovl_builtin_operand_types_begin
                    (&local_50,left,pattern_00,
                     (uint)(byte)((c1_builtin_operator_row *)rows)->need_lvalue);
          cVar4 = ovl_builtin_operand_types_next((int *)&local_50);
          while (cVar4 != '\0') {
            ovl_add_builtin_candidate
                      (frame,(c1_builtin_operator_row *)rows,local_50.type,(c1_type *)0x0,count);
            cVar4 = ovl_builtin_operand_types_next((int *)&local_50);
          }
        }
        else {
          cVar4 = (char)pattern->code;
          pcVar3 = pattern;
          while (cVar4 < '\0') {
            pcVar3 = pcVar3->base;
            cVar4 = (char)pcVar3->code;
          }
          if ((pcVar3->code & 0xfff) == 0x809) {
            iVar5 = 0;
            ovl_builtin_operand_types_begin
                      (&local_50,left,pattern_00,
                       (byte)((c1_builtin_operator_row *)rows)->need_lvalue);
            cVar4 = ovl_builtin_operand_types_next((int *)&local_50);
            if (cVar4 != '\0') {
              do {
                ovl_add_builtin_candidate
                          (frame,(c1_builtin_operator_row *)rows,local_50.type,local_50.type,count);
                iVar5 = iVar5 + 1;
                cVar4 = ovl_builtin_operand_types_next((int *)&local_50);
              } while (cVar4 != '\0');
              if (iVar5 != 0) {
                ovl_builtin_operand_types_begin
                          (&local_28,right,pattern_00,
                           (byte)((c1_builtin_operator_row *)rows)->need_lvalue);
                cVar4 = ovl_builtin_operand_types_next((int *)&local_28);
                while (cVar4 != '\0') {
                  ovl_add_builtin_candidate
                            (frame,(c1_builtin_operator_row *)rows,local_28.type,local_28.type,count
                            );
                  cVar4 = ovl_builtin_operand_types_next((int *)&local_28);
                }
              }
            }
          }
          else {
            ovl_builtin_operand_types_begin
                      (&local_50,left,pattern_00,
                       (uint)(byte)((c1_builtin_operator_row *)rows)->need_lvalue);
            cVar4 = ovl_builtin_operand_types_next((int *)&local_50);
            while (cVar4 != '\0') {
              ovl_builtin_operand_types_begin(&local_28,right,pattern,0);
              cVar4 = ovl_builtin_operand_types_next((int *)&local_28);
              while (cVar4 != '\0') {
                ovl_add_builtin_candidate
                          (frame,(c1_builtin_operator_row *)rows,local_50.type,local_28.type,count);
                cVar4 = ovl_builtin_operand_types_next((int *)&local_28);
              }
              cVar4 = ovl_builtin_operand_types_next((int *)&local_50);
            }
          }
        }
      }
      pcVar1 = (c1_builtin_operator_row *)((int)rows + 0x14);
      rows = (char *)((int)rows + 0x14);
    } while ((char)pcVar1->op == cVar2);
  }
  return;
}

