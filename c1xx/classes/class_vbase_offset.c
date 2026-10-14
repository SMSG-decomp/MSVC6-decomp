int __cdecl class_vbase_offset(int vbase,int cls)

{
  c1_vbase_record *pcVar1;
  
  pcVar1 = class_find_base_record
                     ((c1_symbol *)vbase,*(c1_vbase_vector **)(*(int *)(cls + 0x24) + 0x10));
  return pcVar1->offset;
}

