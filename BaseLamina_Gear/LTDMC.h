#ifndef _DMC_LIB_H
#define _DMC_LIB_H

#ifndef TRUE
#define TRUE  1
#endif

#ifndef FALSE
#define FALSE 0
#endif

#ifndef NULL
#ifdef  __cplusplus
#define NULL    0
#else
#define NULL    ((void *)0)
#endif
#endif

typedef unsigned long       DWORD;
typedef int                 BOOL;
typedef unsigned char       BYTE;
typedef unsigned short      WORD;
typedef float               FLOAT;

#define __DMC_EXPORTS

//������������
#ifdef __DMC_EXPORTS
	#define DMC_API __declspec(dllexport)
#else
	#define DMC_API __declspec(dllimport)
#endif

#ifdef __cplusplus
extern "C" {
#endif

//�忨����	
DMC_API short __stdcall dmc_board_init(void); 	//��ʼ�����ƿ�
DMC_API short __stdcall dmc_board_close(void);	//�رտ��ƿ�
DMC_API short __stdcall dmc_board_reset(void); //Ӳ����λ
DMC_API short __stdcall	dmc_get_CardInfList(WORD* CardNun,DWORD* CardTypeList,WORD* CardIdList);//��ȡ��ʼ����ɺ�Ŀ���Ϣ�б�
DMC_API short __stdcall dmc_get_CardNo_version(WORD CardNo,DWORD *CardVersion);	//��ȡ���ƿ�Ӳ���汾
DMC_API short __stdcall dmc_get_CardNo_soft_version(WORD CardNo,DWORD *FirmID,DWORD *SubFirmID);	//��ȡ���ƿ�Ӳ���Ĺ̼��汾
DMC_API short __stdcall dmc_get_CardNo_lib_version(DWORD *LibVer);	//��ȡ���ƿ���̬��汾
DMC_API short __stdcall dmc_get_total_axes(WORD CardNo,DWORD *TotalAxis); 	//��ȡָ��������
//�������ӡ������� mode��0-�������1-���
DMC_API short __stdcall dmc_set_debug_mode(WORD mode,const char *FileName);
DMC_API short __stdcall dmc_get_debug_mode(WORD* mode,char *FileName);
//3800ר�� ��IOӳ������
DMC_API short __stdcall dmc_set_AxisIoMap(WORD CardNo,WORD Axis,WORD MsgType,WORD MapPortType,WORD MapPortIndex,DWORD Filter); 
DMC_API short __stdcall dmc_get_AxisIoMap(WORD CardNo,WORD Axis,WORD MsgType,WORD* MapPortType,WORD* MapPortIndex,DWORD* Filter); 
//���Ϻ����Ժ���Ϊ��λ�ɼ���ʹ�ã��º�����ʱ��ͳһ����Ϊ��λ
DMC_API short __stdcall dmc_set_axis_io_map(WORD CardNo,WORD Axis,WORD IoType,WORD MapIoType,WORD MapIoIndex,double filter_time);
DMC_API short __stdcall dmc_get_axis_io_map(WORD CardNo,WORD Axis,WORD IoType,WORD* MapIoType,WORD* MapIoIndex,double* filter_time);
DMC_API short __stdcall dmc_set_special_input_filter(WORD CardNo,double filter_time);//��������ר��IO�˲�ʱ��

//���ز����ļ�
DMC_API short __stdcall dmc_download_configfile(WORD CardNo,const char *FileName);
//���ع̼��ļ�
DMC_API short __stdcall dmc_download_firmware(WORD CardNo,const char *FileName);
//��λ/�쳣����
DMC_API short __stdcall dmc_set_softlimit(WORD CardNo,WORD axis,WORD enable, WORD source_sel,WORD SL_action, long N_limit,long P_limit);	//��������λ����
DMC_API short __stdcall dmc_get_softlimit(WORD CardNo,WORD axis,WORD *enable, WORD *source_sel,WORD *SL_action,long *N_limit,long *P_limit);	//��ȡ����λ����
DMC_API short __stdcall dmc_set_el_mode(WORD CardNo,WORD axis,WORD el_enable,WORD el_logic,WORD el_mode); 	//����EL�ź�
DMC_API short __stdcall dmc_get_el_mode(WORD CardNo,WORD axis,WORD *el_enable,WORD *el_logic,WORD *el_mode); 	//��ȡ����EL�ź�
DMC_API short __stdcall dmc_set_emg_mode(WORD CardNo,WORD axis,WORD enable,WORD emg_logic); 	//����EMG�ź�
DMC_API short __stdcall dmc_get_emg_mode(WORD CardNo,WORD axis,WORD *enable,WORD *emg_logic); 	//��ȡ����EMG�ź�

//3800ר�� �ⲿ����ֹͣ�źż�����ֹͣʱ������
DMC_API short __stdcall dmc_set_dstp_mode(WORD CardNo,WORD axis,WORD enable,WORD logic,DWORD time); 	
DMC_API short __stdcall dmc_get_dstp_mode(WORD CardNo,WORD axis,WORD *enable,WORD *logic,DWORD *time); 	
DMC_API short __stdcall dmc_set_dstp_time(WORD CardNo,WORD axis,DWORD time);
DMC_API short __stdcall dmc_get_dstp_time(WORD CardNo,WORD axis,DWORD *time);
//���Ϻ����Ժ���Ϊ��λ�ɼ���ʹ�ã��º�����ʱ��ͳһ����Ϊ��λ
DMC_API short __stdcall dmc_set_io_dstp_mode(WORD CardNo,WORD axis,WORD enable,WORD logic); //�����ⲿIO��������ֹͣģʽ
DMC_API short __stdcall dmc_get_io_dstp_mode(WORD CardNo,WORD axis,WORD *enable,WORD *logic); 	
DMC_API short __stdcall dmc_set_dec_stop_time(WORD CardNo,WORD axis,double  stop_time);//����ȫ�ּ���ֹͣʱ��
DMC_API short __stdcall dmc_get_dec_stop_time(WORD CardNo,WORD axis,double * stop_time);

//�ٶ�����		
DMC_API short __stdcall dmc_set_profile(WORD CardNo,WORD axis,double Min_Vel,double Max_Vel,double Tacc,double Tdec,double stop_vel);	//�趨�ٶ����߲���
DMC_API short __stdcall dmc_get_profile(WORD CardNo,WORD axis,double *Min_Vel,double *Max_Vel,double *Tacc,double *Tdec,double *stop_vel);	//��ȡ�ٶ����߲���
DMC_API short __stdcall dmc_set_s_profile(WORD CardNo,WORD axis,WORD s_mode,double s_para);	//����ƽ���ٶ����߲���
DMC_API short __stdcall dmc_get_s_profile(WORD CardNo,WORD axis,WORD s_mode,double *s_para);	//��ȡƽ���ٶ����߲���
DMC_API short __stdcall dmc_set_vector_profile_multicoor(WORD CardNo,WORD Crd, double Min_Vel,double Max_Vel,double Tacc,double Tdec=0,double Stop_Vel=0);
DMC_API short __stdcall dmc_get_vector_profile_multicoor(WORD CardNo,WORD Crd, double *Min_Vel,double *Max_Vel,double *Tacc,double *Tdec=NULL,double *Stop_Vel=NULL);

//�˶�ģ������ģʽ		
DMC_API short __stdcall dmc_set_pulse_outmode(WORD CardNo,WORD axis,WORD outmode);	//�趨�������ģʽ
DMC_API short __stdcall dmc_get_pulse_outmode(WORD CardNo,WORD axis,WORD* outmode);	//��ȡ�������ģʽ

//�����˶�		
DMC_API short __stdcall dmc_pmove(WORD CardNo,WORD axis,long dist,WORD posi_mode);	//ָ����������λ���˶�
DMC_API short __stdcall dmc_vmove(WORD CardNo,WORD axis,WORD dir);	//ָ�����������˶�

//PVT�˶�
DMC_API short __stdcall dmc_PvtTable(WORD CardNo,WORD iaxis,DWORD count,double *pTime,long *pPos,double *pVel);
DMC_API short __stdcall dmc_PtsTable(WORD CardNo,WORD iaxis,DWORD count,double *pTime,long *pPos,double *pPercent);
DMC_API short __stdcall dmc_PvtsTable(WORD CardNo,WORD iaxis,DWORD count,double *pTime,long *pPos,double velBegin,double velEnd);
DMC_API short __stdcall dmc_PttTable(WORD CardNo,WORD iaxis,DWORD count,double *pTime,long *pPos);
DMC_API short __stdcall dmc_PvtMove(WORD CardNo,WORD AxisNum,WORD* AxisList);

//���߱�λ/����
DMC_API short __stdcall dmc_reset_target_position(WORD CardNo,WORD axis,long dist,WORD posi_mode=0);	//�˶��иı�Ŀ��λ��
DMC_API short __stdcall dmc_change_speed(WORD CardNo,WORD axis,double Curr_Vel,double Taccdec);	//���߸ı�ָ����ĵ�ǰ�˶��ٶȼ��Ӽ���ʱ��
DMC_API short __stdcall dmc_update_target_position(WORD CardNo,WORD axis,long dist,WORD posi_mode=0);	//ǿ�иı�Ŀ��λ��

//ֱ�߲岹		
DMC_API short __stdcall dmc_line_multicoor(WORD CardNo,WORD Crd,WORD axisNum,WORD *axisList,long *DistList,WORD posi_mode);	//ָ����ֱ�߲岹�˶�
DMC_API short __stdcall dmc_arc_move_multicoor(WORD CardNo,WORD Crd,WORD *AxisList,long *Target_Pos,long *Cen_Pos,WORD Arc_Dir,WORD posi_mode);

//�����˶�	
DMC_API short __stdcall dmc_set_home_pin_logic(WORD CardNo,WORD axis,WORD org_logic,double filter=0); 	//����HOME�ź�
DMC_API short __stdcall dmc_get_home_pin_logic(WORD CardNo,WORD axis,WORD *org_logic,double *filter=NULL); 	//��ȡ����HOME�ź�	
DMC_API short __stdcall dmc_set_homemode(WORD CardNo,WORD axis,WORD home_dir,double vel_mode,WORD mode,WORD EZ_count=0);//�趨ָ����Ļ�ԭ��ģʽ
DMC_API short __stdcall dmc_get_homemode(WORD CardNo,WORD axis,WORD *home_dir, double *vel_mode,WORD *home_mode,WORD *EZ_count=NULL);//��ȡָ����Ļ�ԭ��ģʽ
DMC_API short __stdcall dmc_home_move(WORD CardNo,WORD axis);	
//3410ר�� ��ԭ������ź�����
//DMC_API short __stdcall dmc_set_sd_mode(WORD CardNo,WORD axis,WORD enable,WORD sd_logic,WORD sd_mode); 	//����SD�ź�
//DMC_API short __stdcall dmc_get_sd_mode(WORD CardNo,WORD axis,WORD* enable,WORD *sd_logic,WORD *sd_mode); 	//��ȡ����SD�ź�
//3800ר�� ԭ������
DMC_API short __stdcall dmc_set_homelatch_mode(WORD CardNo,WORD axis,WORD enable,WORD logic,WORD source);//����ԭ������ģʽ
DMC_API short __stdcall dmc_get_homelatch_mode(WORD CardNo,WORD axis,WORD* enable,WORD* logic,WORD* source);
DMC_API long __stdcall dmc_get_homelatch_flag(WORD CardNo,WORD axis);//��ȡ�����־
DMC_API short __stdcall dmc_reset_homelatch_flag(WORD CardNo,WORD axis);//��λԭ�������־
DMC_API long __stdcall dmc_get_homelatch_value(WORD CardNo,WORD axis);//��ȡ����ֵ

//�����˶�	
//3800ר�� ����ͨ��ѡ��	
DMC_API short __stdcall dmc_set_handwheel_channel(WORD CardNo,WORD index);
DMC_API short __stdcall dmc_get_handwheel_channel(WORD CardNo,WORD* index);
//һ�������źſ��Ƶ������˶�
DMC_API short __stdcall dmc_set_handwheel_inmode(WORD CardNo,WORD axis,WORD inmode,long multi,double vh=0);	//�����������������źŵĹ�����ʽ ���Ƶ���
DMC_API short __stdcall dmc_get_handwheel_inmode(WORD CardNo,WORD axis,WORD *inmode,long *multi,double *vh=NULL);	//��ȡ�������������źŵĹ�����ʽ ���Ƶ���
//һ�������źſ��ƶ�����˶�
DMC_API short __stdcall dmc_set_handwheel_inmode_extern(WORD CardNo,WORD inmode,WORD AxisNum,WORD* AxisList,long* multi);	//�����������������źŵĹ�����ʽ ���ƶ���
DMC_API short __stdcall dmc_get_handwheel_inmode_extern(WORD CardNo,WORD* inmode,WORD* AxisNum,WORD* AxisList,long *multi);	
//����ָ��������������˶�
DMC_API short __stdcall dmc_handwheel_move(WORD CardNo,WORD axis);	

//������		
DMC_API short __stdcall dmc_set_counter_inmode(WORD CardNo,WORD axis,WORD mode);	//�趨�������ļ�����ʽ
DMC_API short __stdcall dmc_get_counter_inmode(WORD CardNo,WORD axis,WORD *mode);	//��ȡ�������ļ�����ʽ
DMC_API long __stdcall dmc_get_encoder(WORD CardNo,WORD axis);	
DMC_API short __stdcall dmc_set_encoder(WORD CardNo,WORD axis,long encoder_value);
DMC_API short __stdcall dmc_set_ez_mode(WORD CardNo,WORD axis,WORD ez_logic,WORD ez_mode=0,double filter=0);	//����EZ�ź�
DMC_API short __stdcall dmc_get_ez_mode(WORD CardNo,WORD axis,WORD *ez_logic,WORD *ez_mode=NULL,double *filter=NULL);	//��ȡ����EZ�ź�

//��������
DMC_API short __stdcall dmc_set_ltc_mode(WORD CardNo,WORD axis,WORD ltc_logic,WORD ltc_mode=0,double filter=0); 	//����LTC�ź�
DMC_API short __stdcall dmc_get_ltc_mode(WORD CardNo,WORD axis,WORD*ltc_logic,WORD*ltc_mode=NULL,double *filter=NULL);	//��ȡ����LTC�ź�
DMC_API short __stdcall dmc_set_latch_mode(WORD CardNo,WORD axis,WORD all_enable,WORD latch_sourcee,WORD latch_channel=0); 	//�������淽ʽ
DMC_API short __stdcall dmc_get_latch_mode(WORD CardNo,WORD axis,WORD *all_enable,WORD* latch_sourcee,WORD *latch_channel=NULL); 
DMC_API short __stdcall dmc_reset_latch_flag(WORD CardNo,WORD axis); 	//��λ��������־
DMC_API short __stdcall dmc_get_latch_flag(WORD CardNo,WORD axis); 	//��ȡ���ƿ�����Ч�������
DMC_API long __stdcall dmc_get_latch_value(WORD CardNo,WORD axis); 	//��ȡ���ƿ�������ֵ������������ģʽ�¶�ȡһ�ο��ƿ�����Ч������������Զ���1,��������ֵ������PC��������
DMC_API short __stdcall dmc_get_latch_flag_extern(WORD CardNo,WORD axis); 	//��ȡ���������������
DMC_API long __stdcall dmc_get_latch_value_extern(WORD CardNo,WORD axis,WORD index); 	//�������Ŷ�ȡPC���������ѱ��������ֵ������ʱ��Ὣ���ƿ��ڵ���Ч����ֵȫ��������PC��������
//LTC�˿ڴ�����ʱ��ͣʱ�� ��λ��΢��
DMC_API short __stdcall dmc_set_latch_stop_time(WORD CardNo,WORD axis,long stop_time); 
DMC_API short __stdcall dmc_get_latch_stop_time(WORD CardNo,WORD axis,long* stop_time);
//DMC3800ר�� LTC�������
DMC_API short __stdcall dmc_SetLtcOutMode(WORD CardNo,WORD axis,WORD enable,WORD bitno);//����LTC�������ģʽ
DMC_API short __stdcall dmc_GetLtcOutMode(WORD CardNo,WORD axis,WORD *enable,WORD* bitno);

//�������λ�ñȽ�		
DMC_API short __stdcall dmc_compare_set_config(WORD CardNo,WORD axis,WORD enable, WORD cmp_source); 	//���ñȽ���
DMC_API short __stdcall dmc_compare_get_config(WORD CardNo,WORD axis,WORD *enable, WORD *cmp_source);	//��ȡ���ñȽ���
DMC_API short __stdcall dmc_compare_clear_points(WORD CardNo,WORD axis); 	//������бȽϵ�
DMC_API short __stdcall dmc_compare_add_point(WORD CardNo,WORD axis,long pos,WORD dir, WORD action,DWORD actpara); 	//��ӱȽϵ�
DMC_API short __stdcall dmc_compare_get_current_point(WORD CardNo,WORD axis,long *pos); 	//��ȡ��ǰ�Ƚϵ�
DMC_API short __stdcall dmc_compare_get_points_runned(WORD CardNo,WORD axis,long *pointNum); 	//��ѯ�Ѿ��ȽϹ��ĵ�
DMC_API short __stdcall dmc_compare_get_points_remained(WORD CardNo,WORD axis,long *pointNum); 	//��ѯ���Լ���ıȽϵ�����

//��ά����λ�ñȽ�
DMC_API short __stdcall dmc_compare_set_config_extern(WORD CardNo,WORD enable, WORD cmp_source); 	//���ñȽ���
DMC_API short __stdcall dmc_compare_get_config_extern(WORD CardNo,WORD *enable, WORD *cmp_source);	//��ȡ���ñȽ���
DMC_API short __stdcall dmc_compare_clear_points_extern(WORD CardNo); 	//������бȽϵ�
DMC_API short __stdcall dmc_compare_add_point_extern(WORD CardNo,WORD* axis,long* pos,WORD* dir, WORD action,DWORD actpara); 	//�������λ�ñȽϵ�
DMC_API short __stdcall dmc_compare_get_current_point_extern(WORD CardNo,long *pos); 	//��ȡ��ǰ�Ƚϵ�
DMC_API short __stdcall dmc_compare_get_points_runned_extern(WORD CardNo,long *pointNum); 	//��ѯ�Ѿ��ȽϹ��ĵ�
DMC_API short __stdcall dmc_compare_get_points_remained_extern(WORD CardNo,long *pointNum); 	//��ѯ���Լ���Ķ�ά�Ƚϵ�����

//����λ�ñȽ� 
DMC_API short __stdcall dmc_hcmp_set_mode(WORD CardNo,WORD hcmp, WORD cmp_mode);//���ø��ٱȽ�ģʽ
DMC_API short __stdcall dmc_hcmp_get_mode(WORD CardNo,WORD hcmp, WORD* cmp_mode);
DMC_API short __stdcall dmc_hcmp_set_config(WORD CardNo,WORD hcmp,WORD axis, WORD cmp_source, WORD cmp_logic,long time);//���ø��ٱȽ���ز���
DMC_API short __stdcall dmc_hcmp_get_config(WORD CardNo,WORD hcmp,WORD* axis, WORD* cmp_source, WORD* cmp_logic,long* time);
DMC_API short __stdcall dmc_hcmp_add_point(WORD CardNo,WORD hcmp, long cmp_pos);//��ӱȽϵ�
DMC_API short __stdcall dmc_hcmp_set_liner(WORD CardNo,WORD hcmp, long Increment,long Count);//�������ԱȽ�ģʽ��ز���
DMC_API short __stdcall dmc_hcmp_get_liner(WORD CardNo,WORD hcmp, long* Increment,long* Count);
DMC_API short __stdcall dmc_hcmp_get_current_state(WORD CardNo,WORD hcmp,long *remained_points,long *current_point=NULL,long *runned_points=NULL); //��ȡ�Ƚ�״̬
DMC_API short __stdcall dmc_hcmp_clear_points(WORD CardNo,WORD hcmp); 	//����Ƚϵ�
DMC_API short __stdcall dmc_read_cmp_pin(WORD CardNo,WORD hcmp); //��ȡ���ٱȽ������״̬
DMC_API short __stdcall dmc_write_cmp_pin(WORD CardNo,WORD hcmp, WORD on_off);

//ͨ��IO		
DMC_API short __stdcall dmc_read_inbit(WORD CardNo,WORD bitno); 	//��ȡ����ڵ�״̬
DMC_API short __stdcall dmc_write_outbit(WORD CardNo,WORD bitno,WORD on_off); 	//��������ڵ�״̬
DMC_API short __stdcall dmc_read_outbit(WORD CardNo,WORD bitno);  	//��ȡ����ڵ�״̬
DMC_API DWORD __stdcall dmc_read_inport(WORD CardNo,WORD portno); 	//��ȡ����˿ڵ�ֵ
DMC_API DWORD __stdcall dmc_read_outport(WORD CardNo,WORD portno=0); 	//��ȡ����˿ڵ�ֵ
DMC_API short __stdcall dmc_write_outport(WORD CardNo,WORD portno,DWORD outport_val);  	//��������˿ڵ�ֵ

//IO�����ʱ��ת
DMC_API short __stdcall dmc_IO_TurnOutDelay(WORD CardNo,WORD bitno,DWORD DelayTime);
//���Ϻ����Ժ���Ϊ��λ�ɼ���ʹ�ã��º�����ʱ��ͳһ����Ϊ��λ
DMC_API short __stdcall dmc_reverse_outbit(WORD CardNo,WORD bitno,double reverse_time);

//3800ר�� IO��������
DMC_API short __stdcall dmc_SetIoCountMode(WORD CardNo,WORD bitno,WORD mode,DWORD filter);
DMC_API short __stdcall dmc_GetIoCountMode(WORD CardNo,WORD bitno,WORD *mode,DWORD* filter);
DMC_API short __stdcall dmc_SetIoCountValue(WORD CardNo,WORD bitno,DWORD CountValue);
DMC_API short __stdcall dmc_GetIoCountValue(WORD CardNo,WORD bitno,DWORD* CountValue);
//���Ϻ����Ժ���Ϊ��λ�ɼ���ʹ�ã��º�����ʱ��ͳһ����Ϊ��λ
DMC_API short __stdcall dmc_set_io_count_mode(WORD CardNo,WORD bitno,WORD mode,double filter_time);//����IO����ģʽ
DMC_API short __stdcall dmc_get_io_count_mode(WORD CardNo,WORD bitno,WORD *mode,double* filter_time);
DMC_API short __stdcall dmc_set_io_count_value(WORD CardNo,WORD bitno,DWORD CountValue);//����IO����ֵ
DMC_API short __stdcall dmc_get_io_count_value(WORD CardNo,WORD bitno,DWORD* CountValue);//��ȡIO����ֵ

//�ŷ�ר��IO		
DMC_API short __stdcall dmc_set_alm_mode(WORD CardNo,WORD axis,WORD enable,WORD alm_logic,WORD alm_action);	//����ALM�ź�
DMC_API short __stdcall dmc_get_alm_mode(WORD CardNo,WORD axis,WORD *enable,WORD *alm_logic,WORD *alm_action);	//��ȡ����ALM�ź�
DMC_API short __stdcall dmc_set_inp_mode(WORD CardNo,WORD axis,WORD enable,WORD inp_logic);	//����INP�ź�
DMC_API short __stdcall dmc_get_inp_mode(WORD CardNo,WORD axis,WORD *enable,WORD *inp_logic);	//��ȡ����INP�ź�
DMC_API short __stdcall dmc_read_rdy_pin(WORD CardNo,WORD axis); 	//��ȡRDY״̬
DMC_API short __stdcall dmc_write_erc_pin(WORD CardNo,WORD axis,WORD on_off); 	//����ERC�ź����
DMC_API short __stdcall dmc_read_erc_pin(WORD CardNo,WORD axis); 
DMC_API short __stdcall dmc_write_sevon_pin(WORD CardNo,WORD axis,WORD on_off); 	//���SEVON�ź�
DMC_API short __stdcall dmc_read_sevon_pin(WORD CardNo,WORD axis); 	//��ȡSEVON�ź�

//DMC3800ר�� ����IOӳ��  ���ڶ�ȡ�˲����IO�ڵ�ƽ״̬
DMC_API short __stdcall dmc_set_io_map_virtual(WORD CardNo,WORD bitno,WORD MapIoType,WORD MapIoIndex,double Filter);
DMC_API short __stdcall dmc_get_io_map_virtual(WORD CardNo,WORD bitno,WORD* MapIoType,WORD* MapIoIndex,double* Filter);
DMC_API short __stdcall dmc_read_inbit_virtual(WORD CardNo,WORD bitno); 	

//�˶�״̬���		
DMC_API double __stdcall dmc_read_current_speed(WORD CardNo,WORD axis);	//��ȡָ����ĵ�ǰ�ٶ�
DMC_API double __stdcall dmc_read_vector_speed(WORD CardNo);	//��ȡ��ǰ���Ĳ岹�ٶ�
DMC_API long __stdcall dmc_get_position(WORD CardNo,WORD axis);	//��ȡָ����ĵ�ǰλ��
DMC_API short __stdcall dmc_set_position(WORD CardNo,WORD axis,long current_position);	//�趨ָ����ĵ�ǰλ��
DMC_API long __stdcall dmc_get_target_position(WORD CardNo,WORD axis);        //��ȡָ�����Ŀ��λ��
DMC_API short __stdcall dmc_check_done(WORD CardNo,WORD axis);	//��ȡָ������˶�״̬
DMC_API DWORD __stdcall dmc_axis_io_status(WORD CardNo,WORD axis);	//��ȡָ�����й��˶��źŵ�״̬
DMC_API short __stdcall dmc_stop(WORD CardNo,WORD axis,WORD stop_mode);	//�������ֹͣ/����ֹͣ
DMC_API short __stdcall dmc_check_done_multicoor(WORD CardNo,WORD Crd); //���ò岹�˶�����ʹ�øú�������˶�״̬
DMC_API short __stdcall dmc_stop_multicoor(WORD CardNo,WORD Crd,WORD stop_mode);//���ò岹�˶�����ʹ�øú���ֹͣ�˶�״̬
DMC_API short __stdcall dmc_emg_stop(WORD CardNo);	//����ֹͣ������
//����ᵽλ״̬
DMC_API short __stdcall  dmc_set_factor_error(WORD CardNo,WORD axis,double factor,long error);//���ñ�����ϵ��������
DMC_API short __stdcall  dmc_get_factor_error(WORD CardNo,WORD axis,double* factor,long* error);//��ȡ������ϵ��������
DMC_API short __stdcall  dmc_check_success_pulse(WORD CardNo,WORD axis);//���ָ��λ�õ�λ���
DMC_API short __stdcall  dmc_check_success_encoder(WORD CardNo,WORD axis);//������������λ�õ�λ���

//3800ר�� ��������ߺ�ͨѶ״̬
DMC_API short __stdcall dmc_LinkState(WORD CardNo,WORD* State);	//����״̬

//�������
DMC_API short __stdcall dmc_check_sn(WORD CardNo, const char * check_sn);//��֤���룬У��3��ʧ��֮���ٴ�У�齫����У��ʧ��
DMC_API short __stdcall dmc_write_sn(WORD CardNo, const char * new_sn);//��д����

//DMC5410 DMC5800ר��
DMC_API short __stdcall dmc_get_axis_run_mode(WORD CardNo, WORD axis,WORD* run_mode);//���˶�ģʽ
DMC_API short __stdcall dmc_get_equiv(WORD CardNo,WORD axis, double *equiv);//���嵱��
DMC_API short __stdcall dmc_set_equiv(WORD CardNo,WORD axis, double equiv);
DMC_API short __stdcall dmc_set_backlash_unit(WORD CardNo,WORD axis,double backlash);//�����϶
DMC_API short __stdcall dmc_get_backlash_unit(WORD CardNo,WORD axis,double *backlash);
DMC_API short __stdcall dmc_set_position_unit(WORD CardNo,WORD axis, double pos);//��ǰָ��λ��
DMC_API short __stdcall dmc_get_position_unit(WORD CardNo,WORD axis, double * pos);
DMC_API short __stdcall dmc_set_encoder_unit(WORD CardNo,WORD axis, double pos);//��ǰ����λ��
DMC_API short __stdcall dmc_get_encoder_unit(WORD CardNo,WORD axis, double * pos);
DMC_API short __stdcall dmc_pmove_unit(WORD CardNo,WORD axis,double Dist,WORD posi_mode);//����
DMC_API short __stdcall dmc_t_pmove_unit(WORD CardNo,WORD axis,double Dist,WORD posi_mode);//�Գ�T�Ͷ���
DMC_API short __stdcall dmc_ex_t_pmove_unit(WORD CardNo,WORD axis,double Dist,WORD posi_mode);//�ǶԳ�T�Ͷ���
DMC_API short __stdcall dmc_s_pmove_unit(WORD CardNo,WORD axis,double Dist,WORD posi_mode);//�Գ�S�Ͷ���
DMC_API short __stdcall dmc_ex_s_pmove_unit(WORD CardNo,WORD axis,double Dist,WORD posi_mode);//�ǶԳ�S�Ͷ���
DMC_API short __stdcall dmc_line_unit(WORD CardNo,WORD Crd,WORD AxisNum,WORD* AxisList,double* Target_Pos,WORD posi_mode);//����ֱ��
DMC_API short __stdcall dmc_arc_move_center_unit(WORD CardNo,WORD Crd,WORD AxisNum,WORD* AxisList,double *Target_Pos,double *Cen_Pos,WORD Arc_Dir,long Circle,WORD posi_mode);//����Բ��Բ��/������/������
DMC_API short __stdcall dmc_arc_move_radius_unit(WORD CardNo,WORD Crd,WORD AxisNum,WORD* AxisList,double *Target_Pos,double Arc_Radius,WORD Arc_Dir,long Circle,WORD posi_mode);//���ΰ뾶Բ��/������
DMC_API short __stdcall dmc_arc_move_3points_unit(WORD CardNo,WORD Crd,WORD AxisNum,WORD* AxisList,double *Target_Pos,double *Mid_Pos,long Circle,WORD posi_mode);//��������Բ��/������
DMC_API short __stdcall dmc_rectangle_move_unit(WORD CardNo,WORD Crd,WORD AxisNum,WORD* AxisList,double* Target_Pos,double* Mark_Pos,long num,WORD rect_mode,WORD posi_mode);//���ξ��β岹
DMC_API short __stdcall dmc_read_current_speed_unit(WORD CardNo,WORD axis, double *current_speed);//�ᵱǰ�����ٶ�
DMC_API short __stdcall dmc_set_vector_profile_unit(WORD CardNo,WORD Crd,double Min_Vel,double Max_Vel,double Tacc,double Tdec,double Stop_Vel);//���β岹�ٶȲ���
DMC_API short __stdcall dmc_get_vector_profile_unit(WORD CardNo,WORD Crd,double* Min_Vel,double* Max_Vel,double* Tacc,double* Tdec,double* Stop_Vel);
DMC_API short __stdcall dmc_set_vector_s_profile(WORD CardNo,WORD Crd,WORD s_mode,double s_para);	//����S���ٶ����߲���
DMC_API short __stdcall dmc_get_vector_s_profile(WORD CardNo,WORD Crd,WORD s_mode,double *s_para);
DMC_API short __stdcall dmc_set_profile_unit(WORD CardNo,WORD axis,double Min_Vel,double Max_Vel,double Tacc,double Tdec,double Stop_Vel);//�����ٶȲ���
DMC_API short __stdcall dmc_get_profile_unit(WORD CardNo,WORD axis,double* Min_Vel,double* Max_Vel,double* Tacc,double* Tdec,double* Stop_Vel);
DMC_API short __stdcall dmc_reset_target_position_unit(WORD CardNo,WORD axis, double New_Pos);//���߱�λ
DMC_API short __stdcall dmc_update_target_position_unit(WORD CardNo,WORD axis, double New_Pos);//ǿ�б�λ
DMC_API short __stdcall dmc_change_speed_unit(WORD CardNo,WORD axis, double New_Vel,double Taccdec);//���߱���
//�����岹
DMC_API short __stdcall dmc_conti_open_list(WORD CardNo,WORD Crd,WORD AxisNum,WORD* AxisList); //������������
DMC_API short __stdcall dmc_conti_close_list(WORD CardNo,WORD Crd);	//�ر�����������
DMC_API short __stdcall dmc_conti_stop_list(WORD CardNo,WORD Crd,WORD stop_mode);	//�����岹��ֹͣ
DMC_API short __stdcall dmc_conti_pause_list(WORD CardNo,WORD Crd);	//�����岹����ͣ
DMC_API short __stdcall dmc_conti_start_list(WORD CardNo,WORD Crd);	//��ʼ�����岹
DMC_API long __stdcall dmc_conti_remain_space(WORD CardNo,WORD Crd);	//�������岹ʣ�໺����
DMC_API long __stdcall dmc_conti_read_current_mark (WORD CardNo,WORD Crd);	//��ȡ��ǰ�����岹�εı��
DMC_API short __stdcall dmc_conti_set_blend(WORD CardNo,WORD Crd,WORD enable);//blend�սǹ���ģʽ
DMC_API short __stdcall dmc_conti_get_blend(WORD CardNo,WORD Crd,WORD* enable);
DMC_API short __stdcall dmc_conti_set_profile_unit(WORD CardNo,WORD Crd,double Min_Vel,double Max_vel,double Tacc,double Tdec,double Stop_Vel);//���������岹�ٶ�
DMC_API short __stdcall dmc_conti_set_s_profile(WORD CardNo,WORD Crd,WORD s_mode,double s_para);//���������岹ƽ��ʱ��
DMC_API short __stdcall dmc_conti_get_s_profile(WORD CardNo,WORD Crd,WORD s_mode,double* s_para);
DMC_API short __stdcall dmc_conti_set_pause_output(WORD CardNo,WORD Crd,WORD action,long mask,long state);//��ͣʱIO��� action��0-��������1-��ͣʱ�����2-��ͣʱ���, ��������ʱ�ָ���3-ֹͣʱ�����
DMC_API short __stdcall dmc_conti_get_pause_output(WORD CardNo,WORD Crd,WORD* action,long* mask,long* state);
DMC_API short __stdcall dmc_conti_set_override(WORD CardNo,WORD Crd,double Percent);//����ÿ���ٶȱ���  ������ָ��
DMC_API short __stdcall dmc_conti_change_speed_ratio (WORD CardNo,WORD Crd,double percent);//�����岹��̬����
DMC_API short __stdcall dmc_conti_get_run_state(WORD CardNo,WORD Crd);//��ȡ�����岹״̬��0-���У�1-��ͣ��2-����ֹͣ��3-�쳣ֹͣ
DMC_API short __stdcall dmc_conti_check_done(WORD CardNo,WORD Crd);//��������岹�˶�״̬��0-���У�1-ֹͣ
DMC_API short __stdcall dmc_conti_wait_input(WORD CardNo,WORD Crd,WORD bitno,WORD on_off,double TimeOut,long mark);//���������岹�ȴ�����
DMC_API short __stdcall dmc_conti_delay_outbit_to_start(WORD CardNo, WORD Crd, WORD bitno,WORD on_off,double delay_value,WORD delay_mode,double ReverseTime);//����ڹ켣�����IO�ͺ����
DMC_API short __stdcall dmc_conti_delay_outbit_to_stop(WORD CardNo, WORD Crd, WORD bitno,WORD on_off,double delay_time,double ReverseTime);//����ڹ켣���յ�IO�ͺ����
DMC_API short __stdcall dmc_conti_ahead_outbit_to_stop(WORD CardNo, WORD Crd, WORD bitno,WORD on_off,double ahead_value,WORD ahead_mode,double ReverseTime);//��Թ켣���յ�IO��ǰ���
DMC_API short __stdcall dmc_conti_accurate_outbit_unit(WORD CardNo, WORD Crd, WORD cmp_no,WORD on_off,WORD map_axis,double rel_dist,WORD pos_source,double ReverseTime);//ȷ��λ�þ�ȷ���
DMC_API short __stdcall dmc_conti_write_outbit(WORD CardNo, WORD Crd, WORD bitno,WORD on_off,double ReverseTime);//����������IO���
DMC_API short __stdcall dmc_conti_clear_io_action(WORD CardNo, WORD Crd, DWORD IoMask);//�������δִ�����IO����,��ֹ����һ��ִ��
DMC_API short __stdcall dmc_conti_delay(WORD CardNo, WORD Crd, double delay_time,long mark);//�����ʱָ��
DMC_API short __stdcall dmc_conti_line_unit(WORD CardNo,WORD Crd,WORD AxisNum,WORD* AxisList,double* Target_Pos,WORD posi_mode,long mark);//�����岹ֱ��
DMC_API short __stdcall dmc_conti_arc_move_center_unit(WORD CardNo,WORD Crd,WORD AxisNum,WORD* AxisList,double *Target_Pos,double *Cen_Pos,WORD Arc_Dir,long Circle,WORD posi_mode,long mark);//Բ���յ�ʽԲ��/������/������/ͬ��Բ
DMC_API short __stdcall dmc_conti_arc_move_radius_unit(WORD CardNo,WORD Crd,WORD AxisNum,WORD* AxisList,double *Target_Pos,double Arc_Radius,WORD Arc_Dir,long Circle,WORD posi_mode,long mark);//�뾶�յ�ʽԲ��/������
DMC_API short __stdcall dmc_conti_arc_move_3points_unit(WORD CardNo,WORD Crd,WORD AxisNum,WORD* AxisList,double *Target_Pos,double *Mid_Pos,long Circle,WORD posi_mode,long mark);//����ʽԲ��/������
DMC_API short __stdcall dmc_conti_set_involute_mode(WORD CardNo,WORD Crd,WORD mode);//��������Բ���
DMC_API short __stdcall dmc_conti_get_involute_mode(WORD CardNo,WORD Crd,WORD* mode);
DMC_API short __stdcall dmc_conti_rectangle_move_unit(WORD CardNo,WORD Crd,WORD AxisNum,WORD* AxisList,double* Target_Pos,double* Mark_Pos,long num,WORD rect_mode,WORD posi_mode,long mark);//���β岹
DMC_API short __stdcall dmc_calculate_arclength_center(double* start_pos,double *target_pos,double *cen_pos, WORD arc_dir,double circle,double* ArcLength);//����Բ��Բ������
DMC_API short __stdcall dmc_calculate_arclength_radius(double* start_pos,double *target_pos,double arc_radius, WORD arc_dir,double circle,double* ArcLength);//����뾶Բ������
DMC_API short __stdcall dmc_calculate_arclength_3point(double *start_pos,double *mid_pos, double *end_pos,double circle,double* ArcLength);//��������Բ������
//DMC5800ר�� PWM��CanIO
DMC_API short __stdcall dmc_set_pwm_enable(WORD CardNo,WORD enable);//7�����л�ΪPWM���
DMC_API short __stdcall dmc_get_pwm_enable(WORD CardNo,WORD* enable);
DMC_API short __stdcall dmc_conti_set_pwm_output(WORD CardNo,WORD Crd, WORD pwm_no,double fDuty, double fFre);//�����岹������PWM���
DMC_API short __stdcall dmc_set_pwm_output(WORD CardNo,WORD pwm_no,double fDuty, double fFre);//����PWM���
DMC_API short __stdcall dmc_get_pwm_output(WORD CardNo,WORD pwm_no,double* fDuty, double* fFre);
DMC_API short __stdcall dmc_conti_set_pwm_follow_speed(WORD CardNo,WORD Crd,WORD pwm_no,WORD mode,double MaxVel,double MaxValue,double OutValue);//PWM�ٶȸ���
DMC_API short __stdcall dmc_conti_get_pwm_follow_speed(WORD CardNo,WORD Crd,WORD pwm_no,WORD* mode,double* MaxVel,double* MaxValue,double* OutValue);

DMC_API short __stdcall dmc_set_can_state(WORD CardNo,WORD NodeNum,WORD state,WORD Baud);//0-�Ͽ���1-���ӣ�2-��λ���Զ�����
DMC_API short __stdcall dmc_get_can_state(WORD CardNo,WORD* NodeNum,WORD* state);////0-�Ͽ���1-���ӣ�2-�쳣
DMC_API short __stdcall dmc_get_can_errcode(WORD CardNo,WORD *Errcode);//��ȡCanIoͨѶ������
DMC_API short __stdcall dmc_write_can_outbit(WORD CardNo,WORD Node,WORD bitno,WORD on_off);
DMC_API short __stdcall dmc_read_can_outbit(WORD CardNo,WORD Node,WORD bitno);
DMC_API short __stdcall dmc_read_can_inbit(WORD CardNo,WORD Node,WORD bitno);
DMC_API short __stdcall dmc_write_can_outport(WORD CardNo,WORD Node,WORD portno,DWORD outport_val);//дCanIo�����
DMC_API DWORD __stdcall dmc_read_can_outport(WORD CardNo,WORD Node,WORD portno);//��ȡCanIo����˿�
DMC_API DWORD __stdcall dmc_read_can_inport(WORD CardNo,WORD Node,WORD portno);//��ȡCanIo����˿�

DMC_API short __stdcall dmc_get_stop_reason(WORD CardNo,WORD axis,long* StopReason);//��ȡֹͣԭ��
DMC_API short __stdcall dmc_clear_stop_reason(WORD CardNo,WORD axis);//���ֹͣԭ��
//DMC3410 ����ֹͣ ��Ӧ 25 26 27 28�����
//DMC_API short __stdcall dmc_set_io_dstp_mode(WORD CardNo,WORD axis,WORD enable,WORD logic); 	//���ü���ֹͣIO����Ч��ƽ //enable:0-���ã�1-��ʱ�����ֹͣ��2-���������ֹͣ
//DMC_API short __stdcall dmc_get_io_dstp_mode(WORD CardNo,WORD axis,WORD *enable,WORD *logic); 
//DMC_API short __stdcall dmc_set_dec_stop_time(WORD CardNo,WORD axis,double time);
//DMC_API short __stdcall dmc_get_dec_stop_time(WORD CardNo,WORD axis,double *time); 
DMC_API short __stdcall dmc_set_dec_stop_dist(WORD CardNo,WORD axis,long dist);	//���ü���ֹͣ����
DMC_API short __stdcall dmc_get_dec_stop_dist(WORD CardNo,WORD axis,long *dist);

//DMC5600���ƽ��ߺ�
DMC_API short __stdcall dmc_set_da_enable(WORD CardNo,WORD enable);//����DA���
DMC_API short __stdcall dmc_get_da_enable(WORD CardNo,WORD* enable);
DMC_API short __stdcall dmc_set_da_output(WORD CardNo,WORD channel,double Vout);//����DA���
DMC_API short __stdcall dmc_get_da_output(WORD CardNo,WORD channel,double* Vout);
#ifdef __cplusplus
}
#endif

#endif