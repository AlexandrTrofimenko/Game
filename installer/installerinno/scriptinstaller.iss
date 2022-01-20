; ��� ����������
#define   Name       "BirdIn"
; ������ ����������
#define   Version    "1.0.0"
; �����-�����������
#define   Publisher  "Alexandr Trofimenko"
; ���� ����� ������������
#define   URL        "http://www.vk.com/alexandrtr"
; ��� ������������ ������
#define   ExeName    "BirdIn.exe"

;------------------------------------------------------------------------------
;   ��������� ���������
;------------------------------------------------------------------------------
[Setup]

; ���������� ������������� ����������, 
;��������������� ����� Tools -> Generate GUID
AppId={{5BED910F-668B-4A74-961D-D719D5960C97}

; ������ ����������, ������������ ��� ���������
AppName={#Name}
AppVersion={#Version}
AppPublisher={#Publisher}
AppPublisherURL={#URL}
AppSupportURL={#URL}
AppUpdatesURL={#URL}

; ���� ��������� ��-���������
DefaultDirName={pf}\{#Name}
; ��� ������ � ���� "����"
DefaultGroupName={#Name}

; �������, ���� ����� ������� ��������� setup � ��� ������������ �����
OutputDir=C:\BirdIn\release\installer\output
OutputBaseFileName=BirdIn

; ���� ������
SetupIconFile=D:\build\itog\img\bird.ico

; ��������� ������
Compression=lzma
SolidCompression=yes

;------------------------------------------------------------------------------
;   ������������� ����� ��� �������� ���������
;------------------------------------------------------------------------------
[Languages]
Name: "english"; MessagesFile: "compiler:Default.isl"; LicenseFile: "License_ENG.txt"
Name: "russian"; MessagesFile: "compiler:Languages\Russian.isl"; LicenseFile: "License_RUS.txt"

;------------------------------------------------------------------------------
;   ����������� - ��������� ������, ������� ���� ��������� ��� ���������
;------------------------------------------------------------------------------
[Tasks]
; �������� ������ �� ������� �����
Name: "desktopicon"; Description: "{cm:CreateDesktopIcon}"; GroupDescription: "{cm:AdditionalIcons}"; Flags: unchecked

;------------------------------------------------------------------------------
;   �����, ������� ���� �������� � ����� �����������
;------------------------------------------------------------------------------
[Files]

; ����������� ����
Source: "D:\itog\Release\BirdIn.exe"; DestDir: "{app}"; Flags: ignoreversion

; ������������� �������
Source: "D:\itog\img\*"; DestDir: "{app}\img\"; Flags: ignoreversion recursesubdirs createallsubdirs
Source: "D:\itog\font\*"; DestDir: "{app}\font\"; Flags: ignoreversion recursesubdirs createallsubdirs
Source: "D:\itog\audio\*"; DestDir: "{app}\audio\"; Flags: ignoreversion recursesubdirs createallsubdirs
; VS Redistributable package
Source: "D:\build\itog\VC_redist.x64.exe"; DestDir: "{tmp}"; Flags: deleteafterinstall
;------------------------------------------------------------------------------
;   ��������� �����������, ��� �� ������ ����� ������
;------------------------------------------------------------------------------ 
[Icons]

Name: "{group}\{#Name}"; Filename: "{app}\{#ExeName}"

Name: "{commondesktop}\{#Name}"; Filename: "{app}\{#ExeName}"; Tasks: desktopicon

[Run]
;------------------------------------------------------------------------------
;   ��������� ����������������� ������ VS
;------------------------------------------------------------------------------
Filename: {tmp}\VC_redist.x64.exe; Parameters: "/q:a /c:""install /l /q"""; StatusMsg: VS redistributable package is installed. Please wait...
