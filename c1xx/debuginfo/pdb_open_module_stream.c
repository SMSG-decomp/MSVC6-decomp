int __thiscall pdb_open_module_stream(void *idb,int unused,char *object_file)

{
  int *stream;
  char *pcVar1;
  int iVar2;
  int *stream_00;
  int iStack_114;
  char local_110 [269];
  char name_last;
  
  pcVar1 = pdb_relative_path(object_file);
  _snprintf(local_110,0x10e,"/ipm/mod/%s",pcVar1);
  name_last = '\0';
  iVar2 = (**(code **)(**(int **)((int)idb + 0x178) + 0x2c))
                    (*(int **)((int)idb + 0x178),"/ipm",(void **)((int)idb + 0x188));
  if (iVar2 != 0) {
    iVar2 = (**(code **)(**(int **)((int)idb + 0x178) + 0x2c))
                      (*(int **)((int)idb + 0x178),local_110,(void **)((int)idb + 400));
    if ((iVar2 != 0) &&
       (((*(int *)((int)idb + 8) == 0 && (*(int *)((int)idb + 0xc) == 0)) ||
        ((iVar2 = (**(code **)(**(int **)((int)idb + 0x17c) + 0x2c))
                            (*(int **)((int)idb + 0x17c),"/ipm",(void **)((int)idb + 0x18c)),
         iVar2 != 0 &&
         (iVar2 = (**(code **)(**(int **)((int)idb + 0x17c) + 0x2c))
                            (*(int **)((int)idb + 0x17c),local_110,(void **)((int)idb + 0x194)),
         iVar2 != 0)))))) {
      if (*(int *)((int)idb + 0xc) == 0) {
        stream = *(void **)((int)idb + 0x188);
        stream_00 = *(void **)((int)idb + 400);
      }
      else {
        stream = *(int **)((int)idb + 0x18c);
        stream_00 = *(int **)((int)idb + 0x194);
      }
      iVar2 = (**(code **)*stream)();
      if ((iVar2 == 0) ||
         ((iVar2 = idb_read_dependencies(idb,stream,&iStack_114), iVar2 != 0 &&
          (((iStack_114 == 0 || (iVar2 = (**(code **)*stream_00)(), iVar2 == 0)) ||
           (iVar2 = idb_read_regions(idb,stream_00), iVar2 != 0)))))) {
        iVar2 = idb_check_file_times(idb);
        return (uint)(iVar2 != 0);
      }
    }
  }
  return 0;
}

