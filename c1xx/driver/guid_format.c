void * __cdecl guid_format(char *format,c1_guid *guid)

{
  void *pvVar1;
  char local_40 [64];
  
  sprintf(local_40,format,guid->Data1,(uint)guid->Data2,(uint)guid->Data3,(uint)guid->Data4[0],
          (uint)guid->Data4[1],(uint)guid->Data4[2],(uint)guid->Data4[3],(uint)guid->Data4[4],
          (uint)guid->Data4[5],(uint)guid->Data4[6],(uint)guid->Data4[7]);
  pvVar1 = name_intern(local_40);
  return pvVar1;
}

