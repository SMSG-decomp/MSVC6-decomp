char * __thiscall idb_header_file_name(void *include_state,void *name_map)

{
  int iVar1;
  
  iVar1 = (**(code **)(*(int *)name_map + 0xc))
                    (name_map,*(ulong *)((int)include_state + 0x38),&name_map);
  if (iVar1 == 0) {
    name_map = "?";
  }
  return name_map;
}

