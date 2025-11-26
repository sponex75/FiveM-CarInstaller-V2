#pragma once

#include <Windows.h>
#include <string>
#include <msclr/marshal_cppstd.h>
#include <filesystem>
#include <fstream>
#include <iostream>

namespace VHFIVEMAUTOINSTALL {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::IO;
	using namespace System::Collections::Generic;

	/// <summary>
	/// Summary for MainForm
	/// </summary>
	public ref class MainForm : public System::Windows::Forms::Form
	{
	public:
		MainForm(void)
		{
			InitializeComponent();
			// Enable dragging the borderless window
			this->MouseDown += gcnew System::Windows::Forms::MouseEventHandler(this, &MainForm::MainForm_MouseDown);
			this->MouseMove += gcnew System::Windows::Forms::MouseEventHandler(this, &MainForm::MainForm_MouseMove);
			this->MouseUp += gcnew System::Windows::Forms::MouseEventHandler(this, &MainForm::MainForm_MouseUp);
			
			// Set Icon from Embedded Resource (Win32)
			try {
				HICON hIcon = LoadIcon(GetModuleHandle(NULL), MAKEINTRESOURCE(1));
				if (hIcon) {
					this->Icon = System::Drawing::Icon::FromHandle(IntPtr(hIcon));
				}
			} catch (...) {}
		}

	protected:
		~MainForm()
		{
			if (components)
			{
				delete components;
			}
		}

	private: 
		System::Windows::Forms::Label^ labelCarFolder;
		System::Windows::Forms::TextBox^ txtCarFolder;
		System::Windows::Forms::Button^ btnBrowseCar;

		System::Windows::Forms::Label^ labelServerFolder;
		System::Windows::Forms::TextBox^ txtServerFolder;
		System::Windows::Forms::Button^ btnBrowseServer;

		System::Windows::Forms::Label^ labelCategory;
		System::Windows::Forms::TextBox^ txtCategory;

		System::Windows::Forms::CheckBox^ chkCarPack;

		System::Windows::Forms::Button^ btnInstall;
		System::Windows::Forms::Label^ labelStatus;
		System::Windows::Forms::FolderBrowserDialog^ folderBrowserDialog;

		// Custom Title Bar
		System::Windows::Forms::Panel^ panelTitleBar;
		System::Windows::Forms::Label^ labelTitle;
		System::Windows::Forms::Button^ btnClose;

		// Dragging variables
		bool dragging;
		System::Drawing::Point dragCursorPoint;
		System::Drawing::Point dragFormPoint;

		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		void InitializeComponent(void)
		{
			this->labelCarFolder = (gcnew System::Windows::Forms::Label());
			this->txtCarFolder = (gcnew System::Windows::Forms::TextBox());
			this->btnBrowseCar = (gcnew System::Windows::Forms::Button());
			this->labelServerFolder = (gcnew System::Windows::Forms::Label());
			this->txtServerFolder = (gcnew System::Windows::Forms::TextBox());
			this->btnBrowseServer = (gcnew System::Windows::Forms::Button());
			this->labelCategory = (gcnew System::Windows::Forms::Label());
			this->txtCategory = (gcnew System::Windows::Forms::TextBox());
			this->chkCarPack = (gcnew System::Windows::Forms::CheckBox());
			this->btnInstall = (gcnew System::Windows::Forms::Button());
			this->labelStatus = (gcnew System::Windows::Forms::Label());
			this->folderBrowserDialog = (gcnew System::Windows::Forms::FolderBrowserDialog());
			this->panelTitleBar = (gcnew System::Windows::Forms::Panel());
			this->labelTitle = (gcnew System::Windows::Forms::Label());
			this->btnClose = (gcnew System::Windows::Forms::Button());
			this->panelTitleBar->SuspendLayout();
			this->SuspendLayout();
			
			// 
			// Colors
			// 
			System::Drawing::Color darkBg = System::Drawing::Color::FromArgb(30, 30, 30);
			System::Drawing::Color darkerBg = System::Drawing::Color::FromArgb(20, 20, 20);
			System::Drawing::Color lightText = System::Drawing::Color::FromArgb(220, 220, 220);
			System::Drawing::Color accentColor = System::Drawing::Color::FromArgb(0, 122, 204);
			System::Drawing::Color controlBg = System::Drawing::Color::FromArgb(45, 45, 48);

			// 
			// panelTitleBar
			// 
			this->panelTitleBar->BackColor = darkerBg;
			this->panelTitleBar->Controls->Add(this->btnClose);
			this->panelTitleBar->Controls->Add(this->labelTitle);
			this->panelTitleBar->Dock = System::Windows::Forms::DockStyle::Top;
			this->panelTitleBar->Location = System::Drawing::Point(0, 0);
			this->panelTitleBar->Name = L"panelTitleBar";
			this->panelTitleBar->Size = System::Drawing::Size(450, 30);
			this->panelTitleBar->TabIndex = 10;
			this->panelTitleBar->MouseDown += gcnew System::Windows::Forms::MouseEventHandler(this, &MainForm::MainForm_MouseDown);
			this->panelTitleBar->MouseMove += gcnew System::Windows::Forms::MouseEventHandler(this, &MainForm::MainForm_MouseMove);
			this->panelTitleBar->MouseUp += gcnew System::Windows::Forms::MouseEventHandler(this, &MainForm::MainForm_MouseUp);
			// 
			// labelTitle
			// 
			this->labelTitle->AutoSize = true;
			this->labelTitle->Font = (gcnew System::Drawing::Font(L"Segoe UI", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->labelTitle->ForeColor = lightText;
			this->labelTitle->Location = System::Drawing::Point(10, 6);
			this->labelTitle->Name = L"labelTitle";
			this->labelTitle->Size = System::Drawing::Size(124, 17);
			this->labelTitle->TabIndex = 0;
			this->labelTitle->Text = L"FiveM CarInstaller V2";
			// 
			// btnClose
			// 
			this->btnClose->Dock = System::Windows::Forms::DockStyle::Right;
			this->btnClose->FlatAppearance->BorderSize = 0;
			this->btnClose->FlatAppearance->MouseOverBackColor = System::Drawing::Color::Red;
			this->btnClose->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->btnClose->ForeColor = lightText;
			this->btnClose->Location = System::Drawing::Point(410, 0);
			this->btnClose->Name = L"btnClose";
			this->btnClose->Size = System::Drawing::Size(40, 30);
			this->btnClose->TabIndex = 1;
			this->btnClose->Text = L"X";
			this->btnClose->UseVisualStyleBackColor = true;
			this->btnClose->Click += gcnew System::EventHandler(this, &MainForm::btnClose_Click);

			// 
			// labelCarFolder
			// 
			this->labelCarFolder->AutoSize = true;
			this->labelCarFolder->Font = (gcnew System::Drawing::Font(L"Segoe UI", 9));
			this->labelCarFolder->ForeColor = lightText;
			this->labelCarFolder->Location = System::Drawing::Point(20, 50);
			this->labelCarFolder->Name = L"labelCarFolder";
			this->labelCarFolder->Size = System::Drawing::Size(65, 15);
			this->labelCarFolder->TabIndex = 0;
			this->labelCarFolder->Text = L"Car Folder:";
			// 
			// txtCarFolder
			// 
			this->txtCarFolder->BackColor = controlBg;
			this->txtCarFolder->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->txtCarFolder->Font = (gcnew System::Drawing::Font(L"Segoe UI", 9));
			this->txtCarFolder->ForeColor = lightText;
			this->txtCarFolder->Location = System::Drawing::Point(23, 68);
			this->txtCarFolder->Name = L"txtCarFolder";
			this->txtCarFolder->Size = System::Drawing::Size(310, 23);
			this->txtCarFolder->TabIndex = 1;
			// 
			// btnBrowseCar
			// 
			this->btnBrowseCar->BackColor = accentColor;
			this->btnBrowseCar->FlatAppearance->BorderSize = 0;
			this->btnBrowseCar->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->btnBrowseCar->Font = (gcnew System::Drawing::Font(L"Segoe UI", 9));
			this->btnBrowseCar->ForeColor = System::Drawing::Color::White;
			this->btnBrowseCar->Location = System::Drawing::Point(345, 67);
			this->btnBrowseCar->Name = L"btnBrowseCar";
			this->btnBrowseCar->Size = System::Drawing::Size(80, 25);
			this->btnBrowseCar->TabIndex = 2;
			this->btnBrowseCar->Text = L"Browse";
			this->btnBrowseCar->UseVisualStyleBackColor = false;
			this->btnBrowseCar->Click += gcnew System::EventHandler(this, &MainForm::btnBrowseCar_Click);
			// 
			// labelServerFolder
			// 
			this->labelServerFolder->AutoSize = true;
			this->labelServerFolder->Font = (gcnew System::Drawing::Font(L"Segoe UI", 9));
			this->labelServerFolder->ForeColor = lightText;
			this->labelServerFolder->Location = System::Drawing::Point(20, 105);
			this->labelServerFolder->Name = L"labelServerFolder";
			this->labelServerFolder->Size = System::Drawing::Size(79, 15);
			this->labelServerFolder->TabIndex = 3;
			this->labelServerFolder->Text = L"Server Folder:";
			// 
			// txtServerFolder
			// 
			this->txtServerFolder->BackColor = controlBg;
			this->txtServerFolder->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->txtServerFolder->Font = (gcnew System::Drawing::Font(L"Segoe UI", 9));
			this->txtServerFolder->ForeColor = lightText;
			this->txtServerFolder->Location = System::Drawing::Point(23, 123);
			this->txtServerFolder->Name = L"txtServerFolder";
			this->txtServerFolder->Size = System::Drawing::Size(310, 23);
			this->txtServerFolder->TabIndex = 4;
			// 
			// btnBrowseServer
			// 
			this->btnBrowseServer->BackColor = accentColor;
			this->btnBrowseServer->FlatAppearance->BorderSize = 0;
			this->btnBrowseServer->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->btnBrowseServer->Font = (gcnew System::Drawing::Font(L"Segoe UI", 9));
			this->btnBrowseServer->ForeColor = System::Drawing::Color::White;
			this->btnBrowseServer->Location = System::Drawing::Point(345, 122);
			this->btnBrowseServer->Name = L"btnBrowseServer";
			this->btnBrowseServer->Size = System::Drawing::Size(80, 25);
			this->btnBrowseServer->TabIndex = 5;
			this->btnBrowseServer->Text = L"Browse";
			this->btnBrowseServer->UseVisualStyleBackColor = false;
			this->btnBrowseServer->Click += gcnew System::EventHandler(this, &MainForm::btnBrowseServer_Click);
			// 
			// labelCategory
			// 
			this->labelCategory->AutoSize = true;
			this->labelCategory->Font = (gcnew System::Drawing::Font(L"Segoe UI", 9));
			this->labelCategory->ForeColor = lightText;
			this->labelCategory->Location = System::Drawing::Point(20, 160);
			this->labelCategory->Name = L"labelCategory";
			this->labelCategory->Size = System::Drawing::Size(126, 15);
			this->labelCategory->TabIndex = 6;
			this->labelCategory->Text = L"Category (e.g. [cars]):";
			// 
			// txtCategory
			// 
			this->txtCategory->BackColor = controlBg;
			this->txtCategory->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->txtCategory->Font = (gcnew System::Drawing::Font(L"Segoe UI", 9));
			this->txtCategory->ForeColor = lightText;
			this->txtCategory->Location = System::Drawing::Point(23, 178);
			this->txtCategory->Name = L"txtCategory";
			this->txtCategory->Size = System::Drawing::Size(310, 23);
			this->txtCategory->TabIndex = 7;
			this->txtCategory->Text = L"[cars]";
			// 
			// chkCarPack
			// 
			this->chkCarPack->AutoSize = true;
			this->chkCarPack->Font = (gcnew System::Drawing::Font(L"Segoe UI", 9));
			this->chkCarPack->ForeColor = lightText;
			this->chkCarPack->Location = System::Drawing::Point(23, 215);
			this->chkCarPack->Name = L"chkCarPack";
			this->chkCarPack->Size = System::Drawing::Size(120, 19);
			this->chkCarPack->TabIndex = 8;
			this->chkCarPack->Text = L"Install as Car Pack (Deep Scan)";
			this->chkCarPack->UseVisualStyleBackColor = true;
			// 
			// btnInstall
			// 
			this->btnInstall->BackColor = System::Drawing::Color::FromArgb(0, 150, 100); // Greenish
			this->btnInstall->FlatAppearance->BorderSize = 0;
			this->btnInstall->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->btnInstall->Font = (gcnew System::Drawing::Font(L"Segoe UI", 11, System::Drawing::FontStyle::Bold));
			this->btnInstall->ForeColor = System::Drawing::Color::White;
			this->btnInstall->Location = System::Drawing::Point(23, 245);
			this->btnInstall->Name = L"btnInstall";
			this->btnInstall->Size = System::Drawing::Size(402, 45);
			this->btnInstall->TabIndex = 9;
			this->btnInstall->Text = L"INSTALL CAR(S)";
			this->btnInstall->UseVisualStyleBackColor = false;
			this->btnInstall->Click += gcnew System::EventHandler(this, &MainForm::btnInstall_Click);
			// 
			// labelStatus
			// 
			this->labelStatus->AutoSize = true;
			this->labelStatus->Font = (gcnew System::Drawing::Font(L"Segoe UI", 9));
			this->labelStatus->ForeColor = System::Drawing::Color::LightGray;
			this->labelStatus->Location = System::Drawing::Point(23, 300);
			this->labelStatus->Name = L"labelStatus";
			this->labelStatus->Size = System::Drawing::Size(0, 15);
			this->labelStatus->TabIndex = 10;
			// 
			// MainForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = darkBg;
			this->ClientSize = System::Drawing::Size(450, 330);
			this->Controls->Add(this->chkCarPack);
			this->Controls->Add(this->panelTitleBar);
			this->Controls->Add(this->txtCategory);
			this->Controls->Add(this->labelCategory);
			this->Controls->Add(this->labelStatus);
			this->Controls->Add(this->btnInstall);
			this->Controls->Add(this->btnBrowseServer);
			this->Controls->Add(this->txtServerFolder);
			this->Controls->Add(this->labelServerFolder);
			this->Controls->Add(this->btnBrowseCar);
			this->Controls->Add(this->txtCarFolder);
			this->Controls->Add(this->labelCarFolder);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::None;
			this->Name = L"MainForm";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"FiveM Car Installer";
			this->panelTitleBar->ResumeLayout(false);
			this->panelTitleBar->PerformLayout();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion

	private: 
		System::Void btnClose_Click(System::Object^ sender, System::EventArgs^ e) {
			this->Close();
		}

		System::Void MainForm_MouseDown(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e) {
			dragging = true;
			dragCursorPoint = System::Windows::Forms::Cursor::Position;
			dragFormPoint = this->Location;
		}

		System::Void MainForm_MouseMove(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e) {
			if (dragging) {
				System::Drawing::Point dif = System::Drawing::Point::Subtract(System::Windows::Forms::Cursor::Position, System::Drawing::Size(dragCursorPoint));
				this->Location = System::Drawing::Point::Add(dragFormPoint, System::Drawing::Size(dif));
			}
		}

		System::Void MainForm_MouseUp(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e) {
			dragging = false;
		}

		System::Void btnBrowseCar_Click(System::Object^ sender, System::EventArgs^ e) {
			if (folderBrowserDialog->ShowDialog() == System::Windows::Forms::DialogResult::OK) {
				txtCarFolder->Text = folderBrowserDialog->SelectedPath;
			}
		}

		System::Void btnBrowseServer_Click(System::Object^ sender, System::EventArgs^ e) {
			if (folderBrowserDialog->ShowDialog() == System::Windows::Forms::DialogResult::OK) {
				txtServerFolder->Text = folderBrowserDialog->SelectedPath;
			}
		}

		void Log(String^ message) {
			try {
				String^ logPath = "install_log.txt";
				String^ timestamp = DateTime::Now.ToString("yyyy-MM-dd HH:mm:ss");
				File::AppendAllText(logPath, "[" + timestamp + "] " + message + Environment::NewLine);
			} catch (...) {}
		}

		System::Void btnInstall_Click(System::Object^ sender, System::EventArgs^ e) {
			String^ carPath = txtCarFolder->Text;
			String^ serverPath = txtServerFolder->Text;
			String^ categoryName = txtCategory->Text;

			Log("Starting installation...");
			Log("Car Path: " + carPath);
			Log("Server Path: " + serverPath);

			if (String::IsNullOrWhiteSpace(carPath) || String::IsNullOrWhiteSpace(serverPath)) {
				labelStatus->ForeColor = System::Drawing::Color::FromArgb(255, 100, 100);
				labelStatus->Text = "Please select both folders.";
				return;
			}

			if (!Directory::Exists(carPath)) {
				labelStatus->ForeColor = System::Drawing::Color::FromArgb(255, 100, 100);
				labelStatus->Text = "Car/Pack folder does not exist.";
				return;
			}

			if (!Directory::Exists(serverPath)) {
				labelStatus->ForeColor = System::Drawing::Color::FromArgb(255, 100, 100);
				labelStatus->Text = "Server folder does not exist.";
				return;
			}

			String^ resourcesPath = Path::Combine(serverPath, "resources");
			if (!Directory::Exists(resourcesPath)) {
				if (Path::GetFileName(serverPath)->ToLower() == "resources") {
					resourcesPath = serverPath;
					serverPath = Directory::GetParent(serverPath)->FullName;
				} else {
					labelStatus->ForeColor = System::Drawing::Color::FromArgb(255, 100, 100);
					labelStatus->Text = "Server folder must contain a 'resources' folder.";
					return;
				}
			}

			if (chkCarPack->Checked) {
				// Pack Mode - Deep Scan
				List<String^>^ carFolders = gcnew List<String^>();
				FindCarFolders(carPath, carFolders);

				if (carFolders->Count == 0) {
					labelStatus->ForeColor = System::Drawing::Color::FromArgb(255, 100, 100);
					labelStatus->Text = "No cars found in pack folder.";
					Log("No cars found in deep scan.");
					return;
				}

				Log("Found " + carFolders->Count + " cars.");
				int successCount = 0;
				int failCount = 0;

				for each (String^ subDir in carFolders) {
					Application::DoEvents(); // Keep UI responsive
					if (InstallSingleCar(subDir, serverPath, resourcesPath, categoryName, false)) {
						successCount++;
					} else {
						failCount++;
					}
				}

				if (failCount == 0) {
					labelStatus->ForeColor = System::Drawing::Color::LightGreen;
					labelStatus->Text = "Deep Scan: Installed " + successCount + " cars successfully!";
				} else {
					labelStatus->ForeColor = System::Drawing::Color::Orange;
					labelStatus->Text = "Installed " + successCount + " cars. Failed: " + failCount;
				}
				Log("Batch finished. Success: " + successCount + ", Fail: " + failCount);

			} else {
				// Single Mode
				if (InstallSingleCar(carPath, serverPath, resourcesPath, categoryName, true)) {
					labelStatus->ForeColor = System::Drawing::Color::LightGreen;
					labelStatus->Text = "Installed successfully!";
				}
			}
		}

		void FindCarFolders(String^ rootPath, List<String^>^ carFolders) {
			try {
				bool hasManifest = File::Exists(Path::Combine(rootPath, "fxmanifest.lua")) || File::Exists(Path::Combine(rootPath, "__resource.lua"));
				bool hasStream = Directory::Exists(Path::Combine(rootPath, "stream"));
				
				array<String^>^ yftFiles = Directory::GetFiles(rootPath, "*.yft");
				bool hasYft = yftFiles->Length > 0;

				if (hasManifest || hasStream || hasYft) {
					carFolders->Add(rootPath);
					return; 
				}

				for each (String^ dir in Directory::GetDirectories(rootPath)) {
					FindCarFolders(dir, carFolders);
				}
			} catch (Exception^ ex) {
				Log("Error scanning: " + ex->Message);
			}
		}

		bool InstallSingleCar(String^ carPath, String^ serverPath, String^ resourcesPath, String^ categoryName, bool showErrors) {
			String^ carName = Path::GetFileName(carPath);
			Log("Installing car: " + carName);
			
			bool hasStream = Directory::Exists(Path::Combine(carPath, "stream"));
			bool hasManifest = File::Exists(Path::Combine(carPath, "fxmanifest.lua")) || File::Exists(Path::Combine(carPath, "__resource.lua"));

			if (!hasStream) {
				System::Windows::Forms::DialogResult result = System::Windows::Forms::DialogResult::Yes;
				
				if (showErrors) {
					result = MessageBox::Show(
						"Stream folder missing in " + carName + ". Auto-structure?",
						"Auto-Structure",
						MessageBoxButtons::YesNo,
						MessageBoxIcon::Question
					);
				}

				if (result == System::Windows::Forms::DialogResult::Yes) {
					try {
						AutoStructureCarFolder(carPath);
						hasStream = true;
						hasManifest = true;
					} catch (Exception^ ex) {
						Log("Auto-structure failed for " + carName + ": " + ex->Message);
						if (showErrors) {
							labelStatus->ForeColor = System::Drawing::Color::FromArgb(255, 100, 100);
							labelStatus->Text = "Auto-structure failed: " + ex->Message;
						}
						return false;
					}
				} else {
					Log("Skipped " + carName + " (missing stream)");
					if (showErrors) {
						labelStatus->ForeColor = System::Drawing::Color::FromArgb(255, 100, 100);
						labelStatus->Text = "Invalid car folder (missing stream).";
					}
					return false;
				}
			}

			if (!hasManifest) {
				System::Windows::Forms::DialogResult result = System::Windows::Forms::DialogResult::Yes;
				
				if (showErrors) {
					result = MessageBox::Show(
						"Manifest missing in " + carName + ". Create it?",
						"Create Manifest",
						MessageBoxButtons::YesNo,
						MessageBoxIcon::Question
					);
				}

				if (result == System::Windows::Forms::DialogResult::Yes) {
					CreateFxManifest(carPath);
					hasManifest = true;
				} else {
					Log("Skipped " + carName + " (missing manifest)");
					if (showErrors) {
						labelStatus->ForeColor = System::Drawing::Color::FromArgb(255, 100, 100);
						labelStatus->Text = "Invalid car folder (missing manifest).";
					}
					return false;
				}
			}

			try {
				String^ destParentPath = resourcesPath;

				if (!String::IsNullOrWhiteSpace(categoryName)) {
					destParentPath = Path::Combine(resourcesPath, categoryName);
					if (!Directory::Exists(destParentPath)) {
						Directory::CreateDirectory(destParentPath);
					}
				}

				String^ destPath = Path::Combine(destParentPath, carName);

				if (Directory::Exists(destPath)) {
					Log("Car " + carName + " already exists.");
					if (showErrors) {
						labelStatus->ForeColor = System::Drawing::Color::FromArgb(255, 100, 100);
						labelStatus->Text = "Car " + carName + " already exists.";
					}
					return false;
				}

				CopyDirectory(carPath, destPath);

				String^ cfgPath = Path::Combine(serverPath, "server.cfg");
				if (File::Exists(cfgPath)) {
					StreamWriter^ sw = File::AppendText(cfgPath);
					sw->WriteLine();
					sw->WriteLine("ensure " + carName);
					sw->Close();
				} 
				
				Log("Successfully installed " + carName);
				return true;

			} catch (Exception^ ex) {
				Log("Error installing " + carName + ": " + ex->Message);
				if (showErrors) {
					labelStatus->ForeColor = System::Drawing::Color::FromArgb(255, 100, 100);
					labelStatus->Text = "Error: " + ex->Message;
				}
				return false;
			}
		}

		void AutoStructureCarFolder(String^ carPath) {
			String^ streamPath = Path::Combine(carPath, "stream");
			Directory::CreateDirectory(streamPath);

			array<String^>^ extensions = { "*.yft", "*.ytd", "*.meta", "*.xml" };
			for each (String^ ext in extensions) {
				for each (String^ file in Directory::GetFiles(carPath, ext)) {
					String^ fileName = Path::GetFileName(file);
					if (ext == "*.yft" || ext == "*.ytd") {
						String^ destFile = Path::Combine(streamPath, fileName);
						File::Move(file, destFile);
					}
				}
			}
			
			CreateFxManifest(carPath);
		}

		void CreateFxManifest(String^ carPath) {
			String^ manifestPath = Path::Combine(carPath, "fxmanifest.lua");
			StreamWriter^ sw = File::CreateText(manifestPath);
			sw->WriteLine("fx_version 'cerulean'");
			sw->WriteLine("game 'gta5'");
			sw->WriteLine("");
			sw->WriteLine("files {");
			sw->WriteLine("    'data/**/*.meta',");
			sw->WriteLine("    'data/**/*.xml',");
			sw->WriteLine("    'data/**/*.dat'");
			sw->WriteLine("}");
			sw->WriteLine("");
			sw->WriteLine("data_file 'HANDLING_FILE' 'data/**/handling.meta'");
			sw->WriteLine("data_file 'VEHICLE_METADATA_FILE' 'data/**/vehicles.meta'");
			sw->WriteLine("data_file 'CARCOLS_FILE' 'data/**/carcols.meta'");
			sw->WriteLine("data_file 'VEHICLE_VARIATION_FILE' 'data/**/carvariations.meta'");
			sw->WriteLine("data_file 'VEHICLE_LAYOUTS_FILE' 'data/**/vehiclelayouts.meta'");
			sw->Close();
			
			String^ dataPath = Path::Combine(carPath, "data");
			if (!Directory::Exists(dataPath)) {
				Directory::CreateDirectory(dataPath);
			}
			
			array<String^>^ metaExtensions = { "*.meta", "*.xml", "*.dat" };
			for each (String^ ext in metaExtensions) {
				for each (String^ file in Directory::GetFiles(carPath, ext)) {
					String^ fileName = Path::GetFileName(file);
					String^ destFile = Path::Combine(dataPath, fileName);
					File::Move(file, destFile);
				}
			}
		}

		void CopyDirectory(String^ sourceDir, String^ destDir) {
			Directory::CreateDirectory(destDir);

			for each (String^ file in Directory::GetFiles(sourceDir)) {
				String^ destFile = Path::Combine(destDir, Path::GetFileName(file));
				File::Copy(file, destFile, true);
			}

			for each (String^ dir in Directory::GetDirectories(sourceDir)) {
				String^ destSubDir = Path::Combine(destDir, Path::GetFileName(dir));
				CopyDirectory(dir, destSubDir);
			}
		}
	};
}
