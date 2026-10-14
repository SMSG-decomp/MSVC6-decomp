c1_node * __cdecl
pm_convert_along_base_path(c1_node *expr,c1_type *target,c1_symbol *base_path,char keep_sign)

{
  int *path;
  c1_u16 cVar1;
  c1_type *pcVar2;
  int iVar3;
  int iVar4;
  c1_node *pcVar5;
  undefined3 in_stack_00000011;
  int local_4;
  
  pcVar2 = target;
  iVar3 = class_complete_type_of(target);
  iVar4 = class_complete_type_of(expr->type);
  cVar1 = pcVar2->code;
  path = *(int **)base_path->type;
  member_path_offset(path,&local_4,(int *)&target);
  if ((char)_keep_sign == '\0') {
    target = (c1_type *)-(int)target;
  }
  pcVar5 = (c1_node *)
           (**(code **)("Jun 17 199810:24:46" +
                       (iVar3 + (iVar4 + (uint)((cVar1 & 0x8f) == 0x8a) * 4) * 4) * 4 + 8))
                     (expr,pcVar2,path,_keep_sign,target,local_4);
  return pcVar5;
}

