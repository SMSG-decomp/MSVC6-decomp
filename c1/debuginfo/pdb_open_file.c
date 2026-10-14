int __cdecl
pdb_open_file(PDB *pdb,PDB *pdb_2,NameMap *name_map,char *source_name,char *object_name,
             c1_source_tracker_iface *tracker,int incremental,int second_pdb,int read_second_pdb,
             c1_idb_state **out_idb)

{
  ulong *puVar1;
  fe_idb_browse_entry *pfVar2;
  fe_idb_region *pfVar3;
  fe_idb_include_state *elements;
  c1_idb_state *pcVar4;
  int iVar5;
  
  if (incremental != 0) {
    if (tracker != (c1_source_tracker_iface *)0x0) {
      pcVar4 = __2_YAPAXI_Z(0x1a4);
      if (pcVar4 != (c1_idb_state *)0x0) {
        pcVar4 = idb_construct(pcVar4,pdb,pdb_2,name_map,tracker,incremental,second_pdb,
                               read_second_pdb);
        if (pcVar4 != (c1_idb_state *)0x0) {
          iVar5 = pdb_open_module_stream(pcVar4,source_name,object_name);
          if (iVar5 != 0) {
            *out_idb = pcVar4;
            return 1;
          }
          pdb_array_destroy(&(pcVar4->unit_files).isetDeleted.rgw);
          pdb_array_destroy(&(pcVar4->unit_files).isetPresent.rgw);
          puVar1 = (pcVar4->unit_files).rgr.rgt;
          if (puVar1 != (ulong *)0x0) {
            __3_YAXPAX_Z(puVar1);
          }
          puVar1 = (pcVar4->unit_files).rgd.rgt;
          if (puVar1 != (ulong *)0x0) {
            __3_YAXPAX_Z(puVar1);
          }
          puVar1 = (pcVar4->names).rgw.rgt;
          if (puVar1 != (ulong *)0x0) {
            __3_YAXPAX_Z(puVar1);
          }
          pfVar2 = (pcVar4->browse_regions).data;
          if (pfVar2 != (fe_idb_browse_entry *)0x0) {
            __3_YAXPAX_Z(pfVar2);
          }
          pfVar3 = (pcVar4->file).regions.data;
          if (pfVar3 != (fe_idb_region *)0x0) {
            __3_YAXPAX_Z(pfVar3);
          }
          pdb_array_destroy(&(pcVar4->dependencies_2).isetDeleted.rgw);
          pdb_array_destroy(&(pcVar4->dependencies_2).isetPresent.rgw);
          puVar1 = (pcVar4->dependencies_2).rgr.rgt;
          if (puVar1 != (ulong *)0x0) {
            __3_YAXPAX_Z(puVar1);
          }
          puVar1 = (pcVar4->dependencies_2).rgd.rgt;
          if (puVar1 != (ulong *)0x0) {
            __3_YAXPAX_Z(puVar1);
          }
          pdb_array_destroy(&(pcVar4->dependencies).isetDeleted.rgw);
          pdb_array_destroy(&(pcVar4->dependencies).isetPresent.rgw);
          puVar1 = (pcVar4->dependencies).rgr.rgt;
          if (puVar1 != (ulong *)0x0) {
            __3_YAXPAX_Z(puVar1);
          }
          pdb_array_destroy(&(pcVar4->dependencies).rgd);
          pdb_array_destroy(&(pcVar4->file_times).isetDeleted.rgw);
          pdb_array_destroy(&(pcVar4->file_times).isetPresent.rgw);
          puVar1 = (pcVar4->file_times).rgr.rgt;
          if (puVar1 != (ulong *)0x0) {
            __3_YAXPAX_Z(puVar1);
          }
          pdb_array_destroy(&(pcVar4->file_times).rgd);
          elements = (pcVar4->include_stack).data;
          if (elements != (fe_idb_include_state *)0x0) {
            pdb_ipm_elem48_vector_deleting_dtor(elements,3);
          }
          __3_YAXPAX_Z(pcVar4);
        }
      }
    }
    *out_idb = (c1_idb_state *)0x0;
    return 0;
  }
  pcVar4 = __2_YAPAXI_Z(4);
  if (pcVar4 != (c1_idb_state *)0x0) {
    pcVar4->vtbl = (c1_idb_vtbl *)&g_idb_stub_vtbl;
    *out_idb = pcVar4;
    return (uint)(pcVar4 != (c1_idb_state *)0x0);
  }
  *out_idb = (c1_idb_state *)0x0;
  return 0;
}

