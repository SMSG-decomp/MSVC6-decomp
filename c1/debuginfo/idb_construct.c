c1_idb_state * __thiscall
idb_construct(c1_idb_state *idb,PDB *pdb,PDB *pdb_2,NameMap *name_map,
             c1_source_tracker_iface *tracker,int incremental,int second_pdb,int read_second_pdb)

{
  ulong *puVar1;
  int iVar2;
  fe_idb_class_record *pfVar3;
  fe_idb_class_record *pfVar4;
  c1_idb_state *local_4;
  
  idb->vtbl = (c1_idb_vtbl *)&PTR__purecall_1065b2a4;
  (idb->include_stack).data = (fe_idb_include_state *)0x0;
  (idb->include_stack).capacity = 0;
  (idb->include_stack).count = 0;
  local_4 = idb;
  puVar1 = __2_YAPAXI_Z(4);
  (idb->file_times).rgd.rgt = puVar1;
  (idb->file_times).rgd.itMax = (uint)(puVar1 != (ulong *)0x0);
  (idb->file_times).rgd.itMac = (uint)(puVar1 != (ulong *)0x0);
  array_init_count(&(idb->file_times).rgr,1);
  il_buffer_init_empty((int *)&(idb->file_times).isetPresent);
  il_buffer_init_empty((int *)&(idb->file_times).isetDeleted);
  (idb->file_times).cdr = 0;
  puVar1 = __2_YAPAXI_Z(4);
  (idb->dependencies).rgd.rgt = puVar1;
  (idb->dependencies).rgd.itMax = (uint)(puVar1 != (ulong *)0x0);
  (idb->dependencies).rgd.itMac = (uint)(puVar1 != (ulong *)0x0);
  array_init_count(&(idb->dependencies).rgr,1);
  il_buffer_init_empty((int *)&(idb->dependencies).isetPresent);
  il_buffer_init_empty((int *)&(idb->dependencies).isetDeleted);
  (idb->dependencies).cdr = 0;
  puVar1 = __2_YAPAXI_Z(4);
  (idb->dependencies_2).rgd.rgt = puVar1;
  (idb->dependencies_2).rgd.itMax = (uint)(puVar1 != (ulong *)0x0);
  (idb->dependencies_2).rgd.itMac = (uint)(puVar1 != (ulong *)0x0);
  array_init_count(&(idb->dependencies_2).rgr,1);
  il_buffer_init_empty((int *)&(idb->dependencies_2).isetPresent);
  il_buffer_init_empty((int *)&(idb->dependencies_2).isetDeleted);
  (idb->dependencies_2).cdr = 0;
  (idb->file).regions.data = (fe_idb_region *)0x0;
  (idb->file).regions.capacity = 0;
  (idb->file).regions.count = 0;
  gi_region_entry_init(&(idb->file).current,0);
  pfVar4 = &(idb->file).pending_class;
  pfVar4->class_ni = 0;
  (idb->file).pending_class.first_region = 0;
  (idb->file).pending_class.unk08 = 0;
  (idb->file).pending_class.depth = 0;
  (idb->file).pending_class.change = 0;
  pfVar4->class_ni = 0;
  (idb->file).cursor = 0;
  pfVar3 = &g_idb_empty_class_record;
  for (iVar2 = 5; iVar2 != 0; iVar2 = iVar2 + -1) {
    pfVar4->class_ni = pfVar3->class_ni;
    pfVar3 = (fe_idb_class_record *)&pfVar3->first_region;
    pfVar4 = (fe_idb_class_record *)&pfVar4->first_region;
  }
  (idb->file).tracker = (MREFile *)0x0;
  (idb->file).name_ni = 0;
  (idb->file).mtime = -1;
  (idb->file).unk40 = 0;
  (idb->file).changed = '\0';
  (idb->file).untracked = '\0';
  (idb->browse_regions).data = (fe_idb_browse_entry *)0x0;
  (idb->browse_regions).capacity = 0;
  (idb->browse_regions).count = 0;
  array_init_count(&(idb->names).rgw,0x200);
  local_4 = (c1_idb_state *)0x0;
  dword_array_fill(&(idb->names).rgw,(c1_u32 *)&local_4);
  map_init(&idb->unit_files,1);
  idb->pdb = pdb;
  idb->pdb_2 = pdb_2;
  idb->name_map = name_map;
  idb->tracker = tracker;
  idb->options_signature = 0xffffffff;
  idb->unk130 = 0xffffffff;
  idb->incremental = incremental;
  idb->vtbl = (c1_idb_vtbl *)&PTR_idb_commit_1065b1bc;
  idb->deps_stream = (Stream *)0x0;
  idb->deps_stream_2 = (Stream *)0x0;
  idb->regions_stream = (Stream *)0x0;
  idb->regions_stream_2 = (Stream *)0x0;
  idb->second_pdb = second_pdb;
  idb->read_second_pdb = read_second_pdb;
  idb->state = 1;
  idb->recompile = 0;
  idb->open_conditionals = 0;
  idb->invalidated = 0;
  idb->force_tracking = 0;
  idb->helper_called = '\0';
  idb->regions_disabled = '\0';
  idb->pch_generation_used = 0;
  idb->pch_generation = 0;
  idb->pch_generation_seen = 0;
  idb->browse_size = 0;
  idb->in_function = '\0';
  idb->pdb_signature = 0;
  idb->pdb_age = 0;
  return idb;
}

