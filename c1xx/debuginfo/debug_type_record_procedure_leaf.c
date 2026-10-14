int __cdecl debug_type_record_procedure_leaf(c1_type *type,uint return_index)

{
  int iVar1;
  int iVar2;
  ushort *body;
  
  iVar1 = debug_type_record_arglist((type->extra).count);
  body = g_cv_record_body;
  *g_cv_record_body = 0x1008;
  *(uint *)(body + 1) = return_index;
  iVar2 = debug_cv_calling_convention(type->flags);
  *(char *)(body + 3) = (char)iVar2;
  *(undefined1 *)((int)body + 7) = 0;
  iVar2 = type_function_param_count((type->extra).params);
  body[4] = (ushort)iVar2;
  *(int *)(body + 5) = iVar1;
  iVar1 = cvserver_emit_type(0xe);
  return iVar1;
}

