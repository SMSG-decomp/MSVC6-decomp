int __cdecl debug_type_record_procedure_leaf(c1_type *type,uint return_index)

{
  ushort *puVar1;
  int iVar2;
  int iVar3;
  
  iVar2 = debug_type_record_arglist((type->extra).params);
  puVar1 = g_cv_record_body;
  *g_cv_record_body = 0x1008;
  *(uint *)(puVar1 + 1) = return_index;
  iVar3 = debug_cv_calling_convention(type->flags);
  *(char *)(puVar1 + 3) = (char)iVar3;
  *(undefined1 *)((int)puVar1 + 7) = 0;
  iVar3 = type_function_param_count((type->extra).params);
  puVar1[4] = (ushort)iVar3;
  *(int *)(puVar1 + 5) = iVar2;
  iVar2 = cvserver_emit_type(0xe);
  return iVar2;
}

