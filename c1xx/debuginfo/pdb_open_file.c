int __cdecl
pdb_open_file(c1xx_pdb *pdb,int arg2,c1_pdb_namemap *name_map,char *source_file,char *object_file,
             void *tracker,int incremental,int arg8,int arg9,c1xx_idb **out)

{
  c1_u32 *pcVar1;
  c1_idb_browse_entry *pcVar2;
  c1_idb_region *pcVar3;
  c1_idb_include_state *states;
  c1xx_idb *pcVar4;
  int iVar5;
  
  if (incremental != 0) {
    if (tracker != (void *)0x0) {
      pcVar4 = __2_YAPAXI_Z(0x1a4);
      if (pcVar4 != (c1xx_idb *)0x0) {
        pcVar4 = idb_construct(pcVar4,pdb,(c1xx_pdb *)arg2,name_map,tracker,incremental,arg8,arg9);
        if (pcVar4 != (c1xx_idb *)0x0) {
          iVar5 = pdb_open_module_stream(pcVar4,(int)source_file,object_file);
          if (iVar5 != 0) {
            *out = pcVar4;
            return 1;
          }
          pdb_array_destroy(&(pcVar4->file_times).deleted);
          pdb_array_destroy(&(pcVar4->file_times).present);
          pcVar1 = (pcVar4->file_times).range.data;
          if (pcVar1 != (c1_u32 *)0x0) {
            __3_YAXPAX_Z(pcVar1);
          }
          pcVar1 = (pcVar4->file_times).domain.data;
          if (pcVar1 != (c1_u32 *)0x0) {
            __3_YAXPAX_Z(pcVar1);
          }
          pcVar1 = (pcVar4->name_hash_bits).data;
          if (pcVar1 != (c1_u32 *)0x0) {
            __3_YAXPAX_Z(pcVar1);
          }
          pcVar2 = (pcVar4->browse_lines).data;
          if (pcVar2 != (c1_idb_browse_entry *)0x0) {
            __3_YAXPAX_Z(pcVar2);
          }
          pcVar3 = (pcVar4->file).regions.data;
          if (pcVar3 != (c1_idb_region *)0x0) {
            __3_YAXPAX_Z(pcVar3);
          }
          pdb_array_destroy(&(pcVar4->header_signatures).deleted);
          pdb_array_destroy(&(pcVar4->header_signatures).present);
          pcVar1 = (pcVar4->header_signatures).range.data;
          if (pcVar1 != (c1_u32 *)0x0) {
            __3_YAXPAX_Z(pcVar1);
          }
          pcVar1 = (pcVar4->header_signatures).domain.data;
          if (pcVar1 != (c1_u32 *)0x0) {
            __3_YAXPAX_Z(pcVar1);
          }
          pdb_array_destroy(&(pcVar4->header_times).deleted);
          pdb_array_destroy(&(pcVar4->header_times).present);
          pcVar1 = (pcVar4->header_times).range.data;
          if (pcVar1 != (c1_u32 *)0x0) {
            __3_YAXPAX_Z(pcVar1);
          }
          pdb_array_destroy(&(pcVar4->header_times).domain);
          pdb_array_destroy(&(pcVar4->old_file_times).deleted);
          pdb_array_destroy(&(pcVar4->old_file_times).present);
          pcVar1 = (pcVar4->old_file_times).range.data;
          if (pcVar1 != (c1_u32 *)0x0) {
            __3_YAXPAX_Z(pcVar1);
          }
          pdb_array_destroy(&(pcVar4->old_file_times).domain);
          states = (pcVar4->include_stack).data;
          if (states != (c1_idb_include_state *)0x0) {
            pdb_ipm_elem48_vector_deleting_dtor(states,3);
          }
          __3_YAXPAX_Z(pcVar4);
        }
      }
    }
    *out = (c1xx_idb *)0x0;
    return 0;
  }
  pcVar4 = __2_YAPAXI_Z(4);
  if (pcVar4 != (c1xx_idb *)0x0) {
    pcVar4->vtbl = (c1xx_idb_vtbl *)&g_idb_stub_vtbl;
    *out = pcVar4;
    return (uint)(pcVar4 != (c1xx_idb *)0x0);
  }
  *out = (c1xx_idb *)0x0;
  return 0;
}

